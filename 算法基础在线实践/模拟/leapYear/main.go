package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	fmt.Printf("请输入年份: \n")

	input := bufio.NewScanner(os.Stdin)

	for input.Scan() {
		y := input.Text()

		if y == "exit" {
			break
		}

		yy, err := strconv.Atoi(y)
		if err != nil {
			panic(err)
		}

		if yy % 400 == 0 {
			fmt.Printf("%d年 是 闰年.\n\n", yy)
		} else if yy % 4 == 0 && yy % 100 != 0 {
			fmt.Printf("%d年 是 闰年.\n\n", yy)
		} else {
			fmt.Printf("%d年 不是 闰年.\n\n", yy)
		}
	}
}