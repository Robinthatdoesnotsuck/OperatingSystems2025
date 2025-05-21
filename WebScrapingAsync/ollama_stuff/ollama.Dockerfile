FROM ollama/ollama:latest

WORKDIR /app

# Copy your Python application files
COPY . .

# Install Python and dependencies
RUN apt-get update && apt-get install -y python3 python3-pip
RUN pip install -r requirements.txt

# Expose the Ollama API port
EXPOSE 11434

# Start Ollama, wait for it to initialize, pull the model, then run your app
CMD ["./start_ollama.sh"]