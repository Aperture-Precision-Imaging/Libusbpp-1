#pragma once

#include "Endpointdefs.h"

#include <memory>

#include "Transfer.h"

namespace LibUSB
{

	/// Endpoint implementation
	class EndpointImpl;

	/// USB endpoint class
	class Endpoint
	{
	public:

		Endpoint(std::shared_ptr<EndpointImpl> pImpl);
		~Endpoint();

		/// Raw Endpoint Address
		uint8_t Address()const;

		/// Endpoint Number
		int Number()const;

		/// Returns the direction of this endpoint
		Direction_t Direction()const;

		/// Returns the transfer type of this endpoint
		Transfer_t TransferType()const;

		/// Returns the synchronization type (ISOCHRONOUS MODE ONLY!)
		Synchronization_t SynchronizationType()const;

		/// Returns the usage type (ISOCHRONOUS MODE ONLY!)
		Usage_t UsageType()const;

		/// Returns the maximum packet size for this endpoint
		int MaxPacketSize()const;

		/// Returns the polling interval (in frames, 1f = 1mS @ low/full speed, 125uS at high), ignore for bulk/control, 1 for iso, 1-255 for interrupt.
		int PollingInterval()const;

	// Transfer

		/// Creates a new data transfer object
		std::shared_ptr<Transfer> CreateTransfer();

		

	protected:
	private:

		/// Endpoint Implementation
		std::shared_ptr<EndpointImpl> m_pEndpointImpl;
	};

}