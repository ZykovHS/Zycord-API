package main
import (
	"crypto/tls"
	"fmt"
	"net"
)
func ConnectGateway(token string, q chan []byte) {
	conn, _ := tls.Dial("tcp", "gateway.discord.gg:443", nil)
	fmt.Fprintf(conn, "GET /?v=10&encoding=json HTTP/1.1\r\nHost: gateway.discord.gg\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\r\nSec-WebSocket-Version: 13\r\n\r\n")
	buf := make([]byte, 65535)
	for {
		n, err := conn.Read(buf)
		if err != nil { return }
		if n > 0 {
			q <- append([]byte(nil), buf[:n]...)
		}
	}
}
