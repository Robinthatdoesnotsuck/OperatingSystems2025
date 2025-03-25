pull:
	docker pull postgres:16

run-without-user-db-port:
	docker run --name postgres-container -e POSTGRES_PASSWORD=super_secure -d postgres:16

run-without-persistence:
	docker run --name postgres-container \
	-e POSTGRES_USER=super_user \
	-e POSTGRES_PASSWORD=super_secure \
	-e POSTGRES_DB=mydatabase \
	-p 5432:5432 -d postgres:16

run-with-persistence:
	docker run --name postgres-container \
	-e POSTGRES_USER=super_user \
	-e POSTGRES_PASSWORD=super_secure \
	-e POSTGRES_DB=mydatabase \
	-v pgdata:/var/lib/postgresql/data \
	-p 5432:5432 -d postgres:16

check-docker-volumes:
	docker volume ls
connect-to-postgres-container-macos:
	pgcli --host localhost -U super_user -d mydatabase