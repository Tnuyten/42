LOW_POS="29"
LOW_NEG="-29"
HIGH_POS="97"
HIGH_NEG="-0"

#==============================================TEST=============================================================
PROG=$(./a.out $LOW_POS $HIGH_POS)
EXPECT=$(bc -q <<EOF
$LOW_POS + $HIGH_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO +l+h ($LOW_POS + $HIGH_POS = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $LOW_POS $HIGH_NEG)
EXPECT=$(bc -q <<EOF
$LOW_POS + $HIGH_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO +l-h ($LOW_POS + $HIGH_NEG = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $LOW_NEG $HIGH_POS)
EXPECT=$(bc -q <<EOF
$LOW_NEG + $HIGH_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO -l+h ($LOW_NEG + $HIGH_POS = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $LOW_NEG $HIGH_NEG)
EXPECT=$(bc -q <<EOF
$LOW_NEG + $HIGH_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO -l-h ($LOW_NEG + $HIGH_NEG = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $HIGH_POS $LOW_POS)
EXPECT=$(bc -q <<EOF
$HIGH_POS + $LOW_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO +h+l ($HIGH_POS + $LOW_POS = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $HIGH_NEG $LOW_POS)
EXPECT=$(bc -q <<EOF
$HIGH_NEG + $LOW_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO -h+l ($HIGH_NEG + $LOW_POS = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $HIGH_POS $LOW_NEG)
EXPECT=$(bc -q <<EOF
$HIGH_POS + $LOW_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO +h-l ($HIGH_POS + $LOW_NEG = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $HIGH_NEG $LOW_NEG)
EXPECT=$(bc -q <<EOF
$HIGH_NEG + $LOW_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO -h-l ($HIGH_NEG + $LOW_NEG = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $HIGH_NEG $HIGH_NEG)
EXPECT=$(bc -q <<EOF
$HIGH_NEG + $HIGH_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO -h-l ($HIGH_NEG + $HIGH_NEG = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $HIGH_POS $HIGH_POS)
EXPECT=$(bc -q <<EOF
$HIGH_POS + $HIGH_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO -h-l ($HIGH_POS + $HIGH_POS = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $LOW_POS $LOW_POS)
EXPECT=$(bc -q <<EOF
$LOW_POS + $LOW_POS
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO -h-l ($LOW_POS + $LOW_POS = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi

#==============================================TEST=============================================================
PROG=$(./a.out $LOW_NEG $LOW_NEG)
EXPECT=$(bc -q <<EOF
$LOW_NEG + $LOW_NEG
EOF
)
if [ "$PROG" != $EXPECT ]; then
    echo "KO -h-l ($LOW_NEG + $LOW_NEG = $PROG, expected $EXPECT)"
else
    echo "OK" $PROG $EXPECT
fi






# PROG=$(./a.out $LOW_POS $HIGH_POS) 1
# PROG=$(./a.out $LOW_POS $HIGH_NEG) 2
# PROG=$(./a.out $LOW_NEG $HIGH_POS) 3
# PROG=$(./a.out $LOW_NEG $HIGH_NEG) 4

# PROG=$(./a.out $HIGH_POS $LOW_POS) 5
# PROG=$(./a.out $HIGH_NEG $LOW_POS) 6
# PROG=$(./a.out $HIGH_POS $LOW_NEG) 7
# PROG=$(./a.out $HIGH_NEG $LOW_NEG) 8

# PROG=$(./a.out $HIGH_NEG $HIGH_NEG) 9
