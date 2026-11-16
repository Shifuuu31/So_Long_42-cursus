#include "../so_long.h"
#include <sys/wait.h>
#include <fcntl.h>

static int g_tests_run = 0;
static int g_tests_passed = 0;
static int g_tests_failed = 0;

#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RED     "\033[31m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_BOLD    "\033[1m"

#define TEST_HEADER(name) \
	printf("\n" COLOR_BOLD COLOR_CYAN "=== [SUITE] %s ===" COLOR_RESET "\n", name)

#define ASSERT_TRUE(desc, expr) do { \
	g_tests_run++; \
	if (expr) { \
		printf("  " COLOR_GREEN "✓" COLOR_RESET " %s\n", desc); \
		g_tests_passed++; \
	} else { \
		printf("  " COLOR_RED "✗" COLOR_RESET " %s (Line %d)\n", desc, __LINE__); \
		g_tests_failed++; \
	} \
} while (0)

#define ASSERT_FALSE(desc, expr) do { \
	g_tests_run++; \
	if (!(expr)) { \
		printf("  " COLOR_GREEN "✓" COLOR_RESET " %s\n", desc); \
		g_tests_passed++; \
	} else { \
		printf("  " COLOR_RED "✗" COLOR_RESET " %s (Line %d)\n", desc, __LINE__); \
		g_tests_failed++; \
	} \
} while (0)

#define ASSERT_EQ_INT(desc, actual, expected) do { \
	g_tests_run++; \
	int a = (actual); \
	int e = (expected); \
	if (a == e) { \
		printf("  " COLOR_GREEN "✓" COLOR_RESET " %s\n", desc); \
		g_tests_passed++; \
	} else { \
		printf("  " COLOR_RED "✗" COLOR_RESET " %s (Expected %d, got %d at line %d)\n", desc, e, a, __LINE__); \
		g_tests_failed++; \
	} \
} while (0)

#define ASSERT_EQ_STR(desc, actual, expected) do { \
	g_tests_run++; \
	const char *a = (actual); \
	const char *e = (expected); \
	if ((a && e && strcmp(a, e) == 0) || (!a && !e)) { \
		printf("  " COLOR_GREEN "✓" COLOR_RESET " %s\n", desc); \
		g_tests_passed++; \
	} else { \
		printf("  " COLOR_RED "✗" COLOR_RESET " %s (Expected \"%s\", got \"%s\" at line %d)\n", desc, e ? e : "NULL", a ? a : "NULL", __LINE__); \
		g_tests_failed++; \
	} \
} while (0)

/* Helper to execute a function that is expected to call exit(1) in a child process */
static int run_expecting_exit_code(void (*func)(void *), void *arg, int expected_exit)
{
	pid_t pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		/* Suppress stderr in child so error messages don't clutter test output */
		int dev_null = open("/dev/null", O_WRONLY);
		if (dev_null != -1)
		{
			dup2(dev_null, 1);
			dup2(dev_null, 2);
			close(dev_null);
		}
		func(arg);
		exit(0); /* If func didn't exit, exit 0 */
	}
	int status = 0;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status) == expected_exit);
	return (0);
}

/* Helper to duplicate map for path check */
void create_tmp_map(t_sl *sl)
{
	int i = 0;
	sl->tmp_map = malloc(sizeof(char *) * (sl->m_h + 1));
	while (sl->map[i])
	{
		sl->tmp_map[i] = ft_strdup(sl->map[i]);
		i++;
	}
	sl->tmp_map[i] = NULL;
}

/* Full validation pipeline runner */
static void run_map_pipeline(void *arg)
{
	char *filename = (char *)arg;
	t_sl sl;

	ft_memset(&sl, 0, sizeof(t_sl));
	check_extention(&sl, filename);
	load_map(&sl, filename);
	check_map_size(&sl);
	check_walls(&sl);
	check_map_elements(&sl);
	create_tmp_map(&sl);
	get_player_position(&sl);
	get_exit_position(&sl);
	check_path(sl.tmp_map, sl.py, sl.px);
	scan_map(&sl);
}

/* ========================================================================= */
/* TEST SUITES                                                               */
/* ========================================================================= */

static void test_libft_functions(void)
{
	TEST_HEADER("Libft String & Memory Utilities");

	/* ft_strlen */
	ASSERT_EQ_INT("ft_strlen: normal string", (int)ft_strlen("42Network"), 9);
	ASSERT_EQ_INT("ft_strlen: empty string", (int)ft_strlen(""), 0);

	/* ft_strdup */
	char *dup = ft_strdup("so_long_game");
	ASSERT_EQ_STR("ft_strdup: duplicate identical string", dup, "so_long_game");
	free(dup);

	/* ft_strncmp */
	ASSERT_TRUE("ft_strncmp: identical strings", ft_strncmp("map.ber", "map.ber", 7) == 0);
	ASSERT_TRUE("ft_strncmp: mismatch string", ft_strncmp("map.ber", "map.txt", 7) != 0);
	ASSERT_TRUE("ft_strncmp: check prefix length", ft_strncmp("map.ber", "map.txt", 3) == 0);

	/* ft_substr */
	char *sub = ft_substr("hello_world", 6, 5);
	ASSERT_EQ_STR("ft_substr: extract substring", sub, "world");
	free(sub);

	/* ft_strjoin (note: frees s1 automatically) */
	char *s1 = ft_strdup("so_");
	char *joined = ft_strjoin(s1, "long");
	ASSERT_EQ_STR("ft_strjoin: join two strings (frees s1)", joined, "so_long");
	free(joined);

	/* ft_split */
	char **tokens = ft_split("11111\n1PCE1\n11111", '\n');
	ASSERT_TRUE("ft_split: tokens array created", tokens != NULL);
	ASSERT_EQ_STR("ft_split: row 0", tokens[0], "11111");
	ASSERT_EQ_STR("ft_split: row 1", tokens[1], "1PCE1");
	ASSERT_EQ_STR("ft_split: row 2", tokens[2], "11111");
	ASSERT_TRUE("ft_split: null terminator", tokens[3] == NULL);
	int i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

static void test_tools_and_helpers(void)
{
	TEST_HEADER("Tools & Extension Validation");

	t_sl sl;
	ft_memset(&sl, 0, sizeof(t_sl));

	/* Extension check */
	ASSERT_EQ_INT("check_extention: valid .ber file", check_extention(&sl, "maps/map.ber"), 0);
	ASSERT_EQ_INT("check_extention: nested path .ber", check_extention(&sl, "maps/level_01.ber"), 0);

	/* compare_c_to_str */
	ASSERT_TRUE("compare_c_to_str: all '1' characters", compare_c_to_str("111111", '1'));
	ASSERT_FALSE("compare_c_to_str: contains '0'", compare_c_to_str("111011", '1'));
	ASSERT_FALSE("compare_c_to_str: contains 'P'", compare_c_to_str("111P11", '1'));
	ASSERT_FALSE("compare_c_to_str: NULL string", compare_c_to_str(NULL, '1'));

	/* element_init */
	sl.p = 5;
	sl.c = 10;
	sl.e = 3;
	element_init(&sl);
	ASSERT_EQ_INT("element_init: p reset to 0", sl.p, 0);
	ASSERT_EQ_INT("element_init: c reset to 0", sl.c, 0);
	ASSERT_EQ_INT("element_init: e reset to 0", sl.e, 0);
}

static void test_invalid_maps(void)
{
	TEST_HEADER("Map Validation: Invalid Maps (Error Handling)");

	struct {
		const char *desc;
		const char *file;
	} invalid_cases[] = {
		{"Non-existent file must fail with exit(1)", "tests/maps_invalid/does_not_exist.ber"},
		{"Empty file must fail with exit(1)", "tests/maps_invalid/empty.ber"},
		{"Wrong extension (.txt) must fail with exit(1)", "tests/maps_invalid/wrong_ext.txt"},
		{"Consecutive newlines must fail with exit(1)", "tests/maps_invalid/consecutive_newlines.ber"},
		{"Non-rectangular map must fail with exit(1)", "tests/maps_invalid/not_rectangular.ber"},
		{"Missing top wall must fail with exit(1)", "tests/maps_invalid/missing_top_wall.ber"},
		{"Missing bottom wall must fail with exit(1)", "tests/maps_invalid/missing_bottom_wall.ber"},
		{"Missing side wall must fail with exit(1)", "tests/maps_invalid/missing_side_wall.ber"},
		{"Missing player (0 'P') must fail with exit(1)", "tests/maps_invalid/missing_player.ber"},
		{"Multiple players (2 'P') must fail with exit(1)", "tests/maps_invalid/multiple_players.ber"},
		{"Missing exit (0 'E') must fail with exit(1)", "tests/maps_invalid/missing_exit.ber"},
		{"Multiple exits (2 'E') must fail with exit(1)", "tests/maps_invalid/multiple_exits.ber"},
		{"Missing collectibles (0 'C') must fail with exit(1)", "tests/maps_invalid/missing_coins.ber"},
		{"Invalid foreign character ('Z') must fail with exit(1)", "tests/maps_invalid/invalid_char.ber"},
		{"Unreachable collectible must fail with exit(1)", "tests/maps_invalid/unreachable_coin.ber"},
		{"Unreachable exit must fail with exit(1)", "tests/maps_invalid/unreachable_exit.ber"},
		{"Collectible trapped behind exit must fail with exit(1)", "tests/maps_invalid/coin_behind_exit.ber"},
	};

	size_t count = sizeof(invalid_cases) / sizeof(invalid_cases[0]);
	for (size_t i = 0; i < count; i++)
	{
		int passed = run_expecting_exit_code(run_map_pipeline, (void *)invalid_cases[i].file, 1);
		ASSERT_TRUE(invalid_cases[i].desc, passed);
	}
}

static void test_valid_maps(void)
{
	TEST_HEADER("Map Validation: Valid Maps");

	struct {
		const char *desc;
		const char *file;
	} valid_cases[] = {
		{"Minimal 5x3 valid map passes validation", "tests/maps_valid/minimal.ber"},
		{"Corridor map passes validation", "tests/maps_valid/corridor.ber"},
		{"Multi-coin room map passes validation", "tests/maps_valid/multi_coin.ber"},
		{"Level 01 campaign map passes validation", "maps/level_01.ber"},
		{"Level 10 campaign map passes validation", "maps/level_10.ber"},
		{"Level 20 max screen map passes validation", "maps/level_20.ber"},
		{"Standard map.ber passes validation", "maps/map.ber"},
		{"Standard tall_map.ber passes validation", "maps/tall_map.ber"}
	};

	size_t count = sizeof(valid_cases) / sizeof(valid_cases[0]);
	for (size_t i = 0; i < count; i++)
	{
		int passed = run_expecting_exit_code(run_map_pipeline, (void *)valid_cases[i].file, 0);
		ASSERT_TRUE(valid_cases[i].desc, passed);
	}
}

static void test_movement_and_game_logic(void)
{
	TEST_HEADER("Game Mechanics & Movement Logic");

	t_sl sl;
	ft_memset(&sl, 0, sizeof(t_sl));

	/* Mock a small 5x5 map */
	char *mock_map[] = {
		"11111",
		"1P0C1",
		"10101",
		"100E1",
		"11111",
		NULL
	};
	sl.map = malloc(sizeof(char *) * 6);
	for (int i = 0; i < 5; i++)
		sl.map[i] = ft_strdup(mock_map[i]);
	sl.map[5] = NULL;
	sl.m_w = 5;
	sl.m_h = 5;
	sl.px = 1;
	sl.py = 1;
	sl.c = 1;
	sl.move_count = 0;

	/* 1. Wall collision check */
	/* Try moving Up into wall (row = -1, col = 0) */
	int target_y = sl.py - 1;
	int target_x = sl.px;
	ASSERT_TRUE("Wall collision: destination is '1'", sl.map[target_y][target_x] == '1');

	/* 2. Valid move right into '0' */
	target_y = sl.py;
	target_x = sl.px + 1;
	ASSERT_TRUE("Free path: destination is '0'", sl.map[target_y][target_x] == '0');
	sl.map[sl.py][sl.px] = '0';
	sl.map[target_y][target_x] = 'P';
	sl.px = target_x;
	sl.py = target_y;
	sl.move_count++;
	ASSERT_EQ_INT("Move player: px updated to 2", sl.px, 2);
	ASSERT_EQ_INT("Move player: py remains 1", sl.py, 1);
	ASSERT_EQ_INT("Move player: move_count incremented to 1", sl.move_count, 1);

	/* 3. Collectible pickup */
	target_y = sl.py;
	target_x = sl.px + 1;
	ASSERT_TRUE("Collectible tile: destination is 'C'", sl.map[target_y][target_x] == 'C');
	sl.c--;
	sl.map[sl.py][sl.px] = '0';
	sl.map[target_y][target_x] = 'P';
	sl.px = target_x;
	sl.py = target_y;
	sl.move_count++;
	ASSERT_EQ_INT("Collectible pickup: coin counter decremented to 0", sl.c, 0);
	ASSERT_EQ_INT("Collectible pickup: px updated to 3", sl.px, 3);
	ASSERT_EQ_INT("Move player: move_count incremented to 2", sl.move_count, 2);

	/* 4. Exit unlock check */
	ASSERT_TRUE("Exit unlocked: all coins collected (c == 0)", sl.c == 0);

	/* Free mock map */
	for (int i = 0; i < 5; i++)
		free(sl.map[i]);
	free(sl.map);
}

/* ========================================================================= */
/* MAIN RUNNER                                                               */
/* ========================================================================= */

int main(void)
{
	/* Ensure we are at repository root regardless of where the binary is invoked from */
	if (access("maps", F_OK) != 0 && access("../maps", F_OK) == 0)
	{
		if (chdir("..") != 0)
			perror("chdir");
	}

	printf("\n" COLOR_BOLD "=========================================================" COLOR_RESET "\n");
	printf(COLOR_BOLD "             SO_LONG AUTOMATED UNIT TEST SUITE            " COLOR_RESET "\n");
	printf(COLOR_BOLD "=========================================================" COLOR_RESET "\n");

	test_libft_functions();
	test_tools_and_helpers();
	test_invalid_maps();
	test_valid_maps();
	test_movement_and_game_logic();

	printf("\n" COLOR_BOLD "=========================================================" COLOR_RESET "\n");
	printf(COLOR_BOLD "TEST SUMMARY:" COLOR_RESET "\n");
	printf("  Total Assertions: %d\n", g_tests_run);
	printf("  Passed:           " COLOR_GREEN "%d" COLOR_RESET "\n", g_tests_passed);
	if (g_tests_failed > 0)
		printf("  Failed:           " COLOR_RED "%d" COLOR_RESET "\n", g_tests_failed);
	else
		printf("  Failed:           " COLOR_GREEN "0" COLOR_RESET "\n");
	printf(COLOR_BOLD "=========================================================" COLOR_RESET "\n\n");

	if (g_tests_failed > 0)
	{
		printf(COLOR_RED COLOR_BOLD "FAIL: Some unit tests did not pass." COLOR_RESET "\n\n");
		return (1);
	}
	printf(COLOR_GREEN COLOR_BOLD "SUCCESS: All unit tests passed perfectly!" COLOR_RESET "\n\n");
	return (0);
}
