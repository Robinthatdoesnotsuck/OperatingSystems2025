package api

import (
	"encoding/json"
	"net/http"

	"github.com/Robinthatdoesnotsuck/ParallelServer/models"
	"github.com/gorilla/mux"
)

// GetWord handles HTTP requests for fetching data.
func GetWord(w http.ResponseWriter, r *http.Request) {
	// Extract the search term from the request parameters.
	vars := mux.Vars(r)
	searchTerm, ok := vars["search"]
	if !ok {
		http.Error(w, "Missing search term in the request", http.StatusBadRequest)
		return
	}

	// Create a JSON object (ResponseData) with the search term.
	responseData := models.ResponseData{
		SearchTerm: searchTerm,
	}

	// Set the Content-Type header to indicate that the response is in JSON format.
	w.Header().Set("Content-Type", "application/json")

	// Serialize the responseData to JSON and send it as the HTTP response.
	if err := json.NewEncoder(w).Encode(responseData); err != nil {
		// If there is an error during JSON encoding, respond with an Internal Server Error (500) and the error message.
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}
}
