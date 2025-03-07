package main

import (
	"fmt"
	"time"
)

func someTask(data int) {
	time.Sleep(2 * time.Second)
	fmt.Printf("Task %d executed \n", data)
}

func someTask(id int, data chan int) {

}
