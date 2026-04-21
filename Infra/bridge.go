package main
import "net"
func StartBridge(q chan []byte) {
	l, _ := net.Listen("unix", "/tmp/worker.sock")
	for {
		conn, _ := l.Accept()
		go func(c net.Conn) {
			for msg := range q {
				eng, err := net.Dial("unix", "/tmp/engine.sock")
				if err == nil {
					eng.Write([]byte{1, 0, 0, 0})
					eng.Close()
				}
				c.Write(msg)
			}
		}(conn)
	}
}
