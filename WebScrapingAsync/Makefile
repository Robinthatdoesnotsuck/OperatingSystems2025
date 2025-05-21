run-ollama-container:
	docker run -d --network ollama_bullsheize -v ollama:/root/.ollama -p 11434:11434 --name ollama ollama/ollama
run-with-gpu:
	 docker run -d --gpus=all -v ollama:/root/.ollama -p 11434:11434 --name ollama ollama/ollama
pull-ollama-model:
	docker exec -it ollama ollama pull llama3.2