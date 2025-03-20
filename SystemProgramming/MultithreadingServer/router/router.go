package router

import (
	"github.com/Robinthatdoesnotsuck/ParallelServer/api"

	"github.com/gorilla/mux"
)

func NewRouter() *mux.Router {
	r := mux.NewRouter()
	r.HandleFunc("/word/{search}", api.GetWord).Methods("GET")
	return r
}
