
make re
# ./push_swap
echo "\033[1;33m odd, OK \033[0m"
./push_swap "5 6 8 1 0 15 22 101 4"

echo "\033[1;33m even, OK \033[0m"
./push_swap "-5 -3 0 9 8 7"

echo "\033[1;33m even, OK \033[0m"
./push_swap "5 6 8 1 15 22 101 4"

echo "\033[1;33m odd, OK \033[0m"
./push_swap "-5 -6 -8 -1 0 -15 -22 -101 -4"

echo "\033[1;33m odd, OK \033[0m"
./push_swap "5 6 8 0 15 22 101 4 2"

echo "\033[1;33m even, OK \033[0m"
./push_swap "-5 -6 -8 -1 -15 -22 -101 -4"

echo "\033[1;35m KO \033[0m"
./push_swap "5 6 8 1 0 15 22 101 4a"
echo "\033[1;35m KO \033[0m"
./push_swap "5 6 8 1 0 1a5 22 101 4"
echo "\033[1;35m KO \033[0m"
./push_swap "5 6 8  1 0 1.5 22 101 4"
echo "\033[1;35m KO \033[0m"
./push_swap "5 6 8 1 0 15 22 --101 4"

echo "\033[1;33m odd, OK \033[0m"
./push_swap "5 6 8 1 0 15 22 -101 4"

echo "\033[1;35m even, KO \033[0m"
./push_swap "5 5 6 8 1 0 15 22 101 4"
echo "\033[1;35m even, KO \033[0m"
./push_swap "5 6 8 1 0 15 22 5 101 4"
echo "\033[1;35m even, KO \033[0m"
./push_swap "5 6 8 1 0 15 22 101 4 5"
echo "\033[1;35m odd, KO \033[0m"
./push_swap "5 6 8 1 0 5 15 22 101 4 3"
echo "\033[1;35m odd, KO \033[0m"
./push_swap "3 6 8 1 0 5 15 22 101 4 5"
echo "\033[1;35m odd, KO \033[0m"
./push_swap "5 6 8 1 0 15 0 22 101 4 3"
echo "\033[1;35m odd, KO \033[0m"
./push_swap "5 6 8 1 0 0 15 22 101 4 3"
echo "\033[1;35m odd, KO \033[0m"
./push_swap "5 6 8 1 0 15 22 101 0"
echo "\033[1;35m odd, KO \033[0m"
./push_swap "5 6 8 1 0 0 22 101 33"

echo "\033[1;33m even, OK \033[0m"
./push_swap "9 8 7 6 5 4 3 78"

echo "\033[1;33m OK \033[0m"
./push_swap "1 0 -4"

echo "\033[1;33m OK \033[0m"
./push_swap "-4 1 0"

echo "\033[1;33m OK \033[0m"
./push_swap "1"

echo "\033[1;33m OK \033[0m"
./push_swap "1 2"

echo "\033[1;33m OK \033[0m"
./push_swap "2 1"

echo "\033[1;33m OK \033[0m"
./push_swap "0 5"

echo "\033[1;33m OK \033[0m"
./push_swap "5 0"

echo "\033[1;33m OK \033[0m"
./push_swap "1 2 3"

echo "\033[1;33m OK \033[0m"
./push_swap "1 3 2"

echo "\033[1;33m OK \033[0m"
./push_swap "3 1 2"

echo "\033[1;33m OK \033[0m"
./push_swap "3 2 1"

echo "\033[1;33m OK \033[0m"
./push_swap "7 5 4 6"

echo "\033[1;33m OK \033[0m"
./push_swap "5 7 4 6"

echo "\033[1;33m OK \033[0m"
./push_swap "5 7 6 4"

echo "\033[1;33m OK \033[0m"
./push_swap "4 5 7 6"

echo "\033[1;33m OK \033[0m"
./push_swap "1 5 4 6"

echo "\033[1;33m OK 4 5 7 6 9\033[0m"
./push_swap "4 5 7 6 9"

echo "\033[1;33m OK 4 0 7 6 9\033[0m"
./push_swap "4 0 7 6 9"

echo "\033[1;33m OK 9 5 1 0 8\033[0m"
./push_swap "9 5 1 0 8"

echo "\033[1;33m OK -5 8 1 3 0\033[0m"
./push_swap "-5 8 1 3 0"

echo "\033[1;33m OK 5 8 2 10 3\033[0m"
./push_swap "5 8 2 10 3"

echo "\033[1;35m empty, KO \033[0m"
./push_swap ""
echo "\033[1;35m empty, KO \033[0m"
./push_swap " "