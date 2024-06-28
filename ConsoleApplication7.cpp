#include <iostream>
#include <uWS/uWS.h>
#include <opcode.def>


struct PerSocketData {
	// Ваша структура данных для каждого сокета
};

int main() {
	uWS::App().ws<PerSocketData>("/*", {
	.compression = uWS::SHARED_COMPRESSOR,
	.maxPayloadLength = 16 * 1024 * 1024,
	.idleTimeout = 16,
	.maxBackpressure = 1 * 1024 * 1024,
	.closeOnBackpressureLimit = false,
	.resetIdleTimeoutOnSend = false,
	.sendPingsAutomatically = true,
	.upgrade = nullptr,
	.open = [](auto* ws) {
			// Open event
			},
			.message = [](auto* ws, std::string_view message, uWS::OpCode opCode) {
			ws->send(message, opCode);
			},
			.drain = [](auto* ws) {
				// Check ws->getBufferedAmount() here
				},
				.close = [](auto* ws, int code, std::string_view message) {
					// Close event
					}
		}).listen(8080, [](auto* token) {
						if (token) {
							std::cout « "Listening on port " « 8080 « std::endl;
						}
			}).run();
}
