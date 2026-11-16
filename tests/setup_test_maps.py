import os

invalid_maps = {
    "empty.ber": "",
    "wrong_ext.txt": "11111\n1P0C1\n100E1\n11111\n",
    "consecutive_newlines.ber": "11111\n1P0C1\n\n100E1\n11111\n",
    "not_rectangular.ber": "111111\n1P0C1\n1000E1\n111111\n",
    "missing_top_wall.ber": "10111\n1P0C1\n100E1\n11111\n",
    "missing_bottom_wall.ber": "11111\n1P0C1\n100E1\n10111\n",
    "missing_side_wall.ber": "11111\n0P0C1\n100E1\n11111\n",
    "missing_player.ber": "11111\n100C1\n100E1\n11111\n",
    "multiple_players.ber": "11111\n1P0C1\n1P0E1\n11111\n",
    "missing_exit.ber": "11111\n1P0C1\n10001\n11111\n",
    "multiple_exits.ber": "11111\n1P0C1\n1E0E1\n11111\n",
    "missing_coins.ber": "11111\n1P001\n100E1\n11111\n",
    "invalid_char.ber": "11111\n1P0C1\n10ZE1\n11111\n",
    "unreachable_coin.ber": "1111111\n1P001C1\n1000111\n10000E1\n1111111\n",
    "unreachable_exit.ber": "1111111\n1P000C1\n1000111\n10001E1\n1111111\n",
    "coin_behind_exit.ber": "1111111\n1P00EC1\n1111111\n"
}

valid_maps = {
    "minimal.ber": "11111\n1PCE1\n11111\n",
    "corridor.ber": "11111111111\n1P0000000C1\n10111111101\n100000000E1\n11111111111\n",
    "multi_coin.ber": "1111111111111\n1P000010000C1\n1011101011101\n10C0100010C01\n1010111110101\n100000C0000E1\n1111111111111\n"
}

for name, content in invalid_maps.items():
    with open(os.path.join("tests/maps_invalid", name), "w") as f:
        f.write(content)

for name, content in valid_maps.items():
    with open(os.path.join("tests/maps_valid", name), "w") as f:
        f.write(content)

print(f"Generated {len(invalid_maps)} invalid test maps and {len(valid_maps)} valid test maps.")
