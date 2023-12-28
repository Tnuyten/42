LOW_POS="17"
LOW_NEG="-23"
HIGH_POS="31"
HIGH_NEG="-37"

OPER="*"
BIN="./a.out"

#==============================================TEST=============================================================
PROG=$($BIN $LOW_POS $HIGH_POS)
EXPECT=$(bc -q <<EOF
$LOW_POS $OPER $HIGH_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO +l+h ($LOW_POS $OPER $HIGH_POS = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $LOW_POS $HIGH_NEG)
EXPECT=$(bc -q <<EOF
$LOW_POS $OPER $HIGH_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO +l-h ($LOW_POS $OPER $HIGH_NEG = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $LOW_NEG $HIGH_POS)
EXPECT=$(bc -q <<EOF
$LOW_NEG $OPER $HIGH_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO -l+h ($LOW_NEG $OPER $HIGH_POS = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $LOW_NEG $HIGH_NEG)
EXPECT=$(bc -q <<EOF
$LOW_NEG $OPER $HIGH_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO -l-h ($LOW_NEG $OPER $HIGH_NEG = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $HIGH_POS $LOW_POS)
EXPECT=$(bc -q <<EOF
$HIGH_POS $OPER $LOW_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO +h+l ($HIGH_POS $OPER $LOW_POS = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $HIGH_NEG $LOW_POS)
EXPECT=$(bc -q <<EOF
$HIGH_NEG $OPER $LOW_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO -h+l ($HIGH_NEG $OPER $LOW_POS = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $HIGH_POS $LOW_NEG)
EXPECT=$(bc -q <<EOF
$HIGH_POS $OPER $LOW_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO +h-l ($HIGH_POS $OPER $LOW_NEG = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $HIGH_NEG $LOW_NEG)
EXPECT=$(bc -q <<EOF
$HIGH_NEG $OPER $LOW_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO -h-l ($HIGH_NEG $OPER $LOW_NEG = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $HIGH_NEG $HIGH_NEG)
EXPECT=$(bc -q <<EOF
$HIGH_NEG $OPER $HIGH_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO -h-h ($HIGH_NEG $OPER $HIGH_NEG = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $HIGH_POS $HIGH_POS)
EXPECT=$(bc -q <<EOF
$HIGH_POS $OPER $HIGH_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO +h+h ($HIGH_POS $OPER $HIGH_POS = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $LOW_POS $LOW_POS)
EXPECT=$(bc -q <<EOF
$LOW_POS $OPER $LOW_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO +l+l ($LOW_POS $OPER $LOW_POS = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$($BIN $LOW_NEG $LOW_NEG)
EXPECT=$(bc -q <<EOF
$LOW_NEG $OPER $LOW_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
	echo "KO -l-l ($LOW_NEG $OPER $LOW_NEG = $PROG, expected $EXPECT)"
else
	echo "OK" $PROG $EXPECT
fi






# PROG=$($BIN $LOW_POS $HIGH_POS) 1
# PROG=$($BIN $LOW_POS $HIGH_NEG) 2
# PROG=$($BIN $LOW_NEG $HIGH_POS) 3
# PROG=$($BIN $LOW_NEG $HIGH_NEG) 4

# PROG=$($BIN $HIGH_POS $LOW_POS) 5
# PROG=$($BIN $HIGH_NEG $LOW_POS) 6
# PROG=$($BIN $HIGH_POS $LOW_NEG) 7
# PROG=$($BIN $HIGH_NEG $LOW_NEG) 8

# PROG=$($BIN $HIGH_NEG $HIGH_NEG) 9
