#!/bin/bash

n=8

bit1=$((RANDOM % 2))
bit2=$((RANDOM % 2))
bit4=$((RANDOM % 2))
bit8=$((RANDOM % 2))
bit16=$((RANDOM % 2))
bit32=$((RANDOM % 2))
bit64=$((RANDOM % 2))
bit128=$((RANDOM % 2))

binaryvalue=$(($bit128 * 128 + $bit64 * 64 + $bit32 * 32 + $bit16 * 16 + $bit8 * 8 + $bit4 * 4 + $bit2 * 2 + $bit1 * 1))


echo "$binaryvalue $bit128 $bit64 $bit32 $bit16 $bit8 $bit4 $bit2 $bit1"


