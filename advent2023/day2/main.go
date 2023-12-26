package main

import (
	"fmt"
	"strings"
	"strconv"
	"advent/helper"
)

func Split(r rune) bool {
    return r == ';' || r == ','
}

func possibleGame(eachLine string) (bool, int) {
	pos := strings.Index(eachLine, ":")
	line := eachLine[pos + 2:] // Remove "Game id:"
	
	ans := true
	record := [3]int{0, 0, 0}
	
	eachPiece := strings.FieldsFunc(line, Split)
	for _, piece := range eachPiece {
		infos := strings.Fields(piece)
		num, _ := strconv.Atoi(infos[0])
		color := infos[1]

		switch color {
		case "red":
			if (num > 12) {
				ans = false
			}
			if (num > record[0]) {
				record[0] = num
			}
		case "green":
			if (num > 13) {
				ans = false
			}
			if (num > record[1]) {
				record[1] = num
			}
		case "blue":
			if (num > 14) {
				ans = false
			}
			if (num > record[2]) {
				record[2] = num
			}
		}
	}
	return ans, (record[0] * record[1] * record[2])
}

func main() {
	inputLines := helper.ReadInput("input.txt");

	var part1 int = 0
	var part2 int = 0
	for index, eachLine := range inputLines {
		ans, power := possibleGame(eachLine)
		if ans {
			part1 += index + 1
		}

		part2 += power
	}
	fmt.Printf("Answer of Part 1 is %d \n", part1)
	fmt.Printf("Answer of Part 2 is %d \n", part2)
	
}