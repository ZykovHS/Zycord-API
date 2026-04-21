package main
func main() {
	q := make(chan []byte, 10000)
	go StartBridge(q)
	ConnectGateway("Insert Token", q)
}
