#pragma once
#include "Socket.h"
#include "../Packet/Packet.h"

namespace GNet
{
	class TCPSocket : public Socket
	{
	public:
		TCPSocket();
		TCPSocket(int32_t handle, IPVersion ipVersion);
		TCPSocket(IPVersion ipVersion, int32_t protocol = 0);
		void Connect(const IPEndpoint& ipEndpoint);
		void Bind(const IPEndpoint& ipEndpoint);
		void Listen(const IPEndpoint& ipEndpoint, int32_t backLog);
		TCPSocket Accept();
		TCPSocket Accept(IPEndpoint& ipEndpoint);
		void Send(const void* buffer, size_t bufferSize, int32_t& bytesSent, int32_t flags = 0);
		void Receive(void* buffer, size_t bufferSize, int32_t& bytesRecieved, int32_t flags = 0);

		void SendAll(const void* buffer, size_t bufferSize, int32_t flags = 0);
		void ReceiveAll(void* buffer, size_t bufferSize, int32_t flags = 0);

		void Send(const Packet& packet, int32_t flags = 0);
		void Recieve(Packet& packet, int32_t flags = 0);
	};
}