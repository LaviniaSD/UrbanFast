build:
	docker build -t my-cpp-app .

test:
	docker run --name my-running-app my-cpp-app

stop:
	docker stop my-running-app
	docker rm my-running-app

make sequence_run:
	make stop
	make build
	make test