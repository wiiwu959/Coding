package main

import (
	"fmt"
	"strconv"
	"unicode"
	"advent/helper"
)

type Pair struct {
    x, y interface{}
}
starMap := map[Pair] int

func handleNum(matrix []string, head int, tail int, row int) int {
	var isPart bool = false

	if (row - 1 >= 0) {
		for i := head - 1; i <= tail + 1; i++ {
			if (i >= 0 && i < len(matrix[0])) {
				if (matrix[row - 1][i] != '.') {
					isPart = true
				}
			}
		}
	}

	if (head - 1 >= 0) {
		if (matrix[row][head - 1] != '.') {
			isPart = true
		}
	}

	if (tail + 1 < len(matrix[0])) {
		if (matrix[row][tail + 1] != '.') {
			isPart = true
		}
	}

	if (row + 1 < len(matrix)) {
		for i := head - 1; i <= tail + 1; i++ {
			if (i >= 0 && i < len(matrix[0])) {
				if (matrix[row + 1][i] != '.') {
					isPart = true
				}
			}
		}
	}

	if (isPart) {
		var numString string = ""
		for i := head; i <= tail; i++ {
			numString += string(matrix[row][i])
		}
		valPart, _ := strconv.Atoi(numString)
		return valPart
	}

	return 0
}

func checkPart(matrix []string) int {
	head := -1
	tail := -1
	var sum int = 0
	for row, eachRow := range matrix {
		for column, node := range eachRow {
			if unicode.IsDigit(node) {
				if (head == -1) {
					head = column
					tail = column
				} else {
					tail = column
					if (column == len(eachRow) - 1) {
						sum += handleNum(matrix, head, tail, row)
						head = -1
						tail = -1
					}
				}
			} else {
				if (head != -1) {
					sum += handleNum(matrix, head, tail, row)
					head = -1
					tail = -1
				}
			}
		}
	}
	return sum
}

func main() {
	inputLines := helper.ReadInput("input.txt");

	var part1 int = 0
	// var part2 int = 0

	var matrix[] string
	for _, eachLine := range inputLines {
		matrix = append(matrix, eachLine)
	}

	part1 = checkPart(matrix)
	fmt.Printf("Answer of Part 1 is %d \n", part1)
	// fmt.Printf("Answer of Part 2 is %d \n", part2)
	
}