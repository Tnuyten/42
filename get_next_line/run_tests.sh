BONUS_TEXT="_bonus"


BONUS="$1"

# echo "BONUS: $BONUS"

BFS=2
gcc get_next_line$BONUS.c get_next_line_utils$BONUS.c tester/tester.c tester/color/color.c -D BUFFER_SIZE=$BFS -o prog
echo "\nBUFFER_SIZE [$BFS] \c"
if [ "$BONUS" = "$BONUS_TEXT" ]; then
	echo "WITH BONUS"
else
	echo
fi
./prog

BFS=3
gcc get_next_line$BONUS.c get_next_line_utils$BONUS.c tester/tester.c tester/color/color.c -D BUFFER_SIZE=$BFS -o prog
echo "\nBUFFER_SIZE [$BFS] \c"
if [ "$BONUS" = "$BONUS_TEXT" ]; then
	echo "WITH BONUS"
else
	echo
fi
./prog

BFS=41
gcc get_next_line$BONUS.c get_next_line_utils$BONUS.c tester/tester.c tester/color/color.c -D BUFFER_SIZE=$BFS -o prog
echo "\nBUFFER_SIZE [$BFS] \c"
if [ "$BONUS" = "$BONUS_TEXT" ]; then
	echo "WITH BONUS"
else
	echo
fi
./prog

BFS=42
gcc get_next_line$BONUS.c get_next_line_utils$BONUS.c tester/tester.c tester/color/color.c -D BUFFER_SIZE=$BFS -o prog
echo "\nBUFFER_SIZE [$BFS] \c"
if [ "$BONUS" = "$BONUS_TEXT" ]; then
	echo "WITH BONUS"
else
	echo
fi
./prog

BFS=43
gcc get_next_line$BONUS.c get_next_line_utils$BONUS.c tester/tester.c tester/color/color.c -D BUFFER_SIZE=$BFS -o prog
echo "\nBUFFER_SIZE [$BFS] \c"
if [ "$BONUS" = "$BONUS_TEXT" ]; then
	echo "WITH BONUS"
else
	echo
fi
./prog

BFS=10000
gcc get_next_line$BONUS.c get_next_line_utils$BONUS.c tester/tester.c tester/color/color.c -D BUFFER_SIZE=$BFS -o prog
echo "\nBUFFER_SIZE [$BFS] \c"
if [ "$BONUS" = "$BONUS_TEXT" ]; then
	echo "WITH BONUS"
else
	echo
fi
./prog