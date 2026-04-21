all: engine infra
engine:
	g++ -O3 engine/main.cpp -o engine_bin -lpthread
infra:
	go build -o infra_bin Infra/*.go
clean:
	rm -f engine_bin infra_bin /tmp/engine.sock /tmp/worker.sock
