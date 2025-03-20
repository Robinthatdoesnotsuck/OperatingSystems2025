package config

import (
	"database/sql"
	"fmt"
	"log"

	"github.com/Robinthatdoesnotsuck/ParallelServer/models"
	_ "github.com/go-sql-driver/mysql"
)

var DB *sql.DB

// ConnectDB establishes a connection to MySQL
func ConnectDB() {
	var err error
	dsn := "root:password@tcp(127.0.0.1:3306)/postdb"
	// replace with with your username & password
	fmt.Println("Connecting to database")
	DB, err = sql.Open("mysql", dsn)
	if err != nil {
		log.Fatal(err)
	}
	if err = DB.Ping(); err != nil {
		log.Fatal(err)
	}
	// This sets the db connection in the models package
	models.SetDB(DB)
	fmt.Println("Database connection established")
}
