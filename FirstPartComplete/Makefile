
build-base:
	docker build -t godot-base --build-arg VERSION= --build-arg COMPUTER_ARCH= -f godot.base.Dockerfile .
build-complete:
	docker buildx build --rm --tag complete_godot --file ./godot.complete.Dockerfile .
run-base:

run-complete: