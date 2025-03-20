package models

import "database/sql"

// ResponseData represents the structure of the JSON response.
type ResponseData struct {
	SearchTerm string `json:"searchTerm"`
}

var db *sql.DB

func SetDB(database *sql.DB) {
	db = database
}
