#include "Configuration.h"
#include "ConfigurationImpl.h"


LibUSB::Configuration::Configuration( std::shared_ptr<ConfigurationImpl> pInit )
{
	// Save the implementation object
	m_pConfigImpl_ = pInit;

}

LibUSB::Configuration::~Configuration()
{
	// Destroy Implementation
	m_pConfigImpl_.reset();
}

std::wstring LibUSB::Configuration::DescriptorString()const
{

	// Obtain the config descriptor string
	return m_pConfigImpl_->DescriptorString();

}

uint8_t LibUSB::Configuration::Value() const
{
	return m_pConfigImpl_->getValue();
}

int LibUSB::Configuration::MaxPower() const
{
	return (int)m_pConfigImpl_->getMaxPower() * 2;
}

const unsigned char * LibUSB::Configuration::getExtraDescriptors() const
{
	return m_pConfigImpl_->getExtraDescriptors();
}

int LibUSB::Configuration::getExtraDescriptorSize() const
{
	return m_pConfigImpl_->getExtraDescriptorSize();
}

void LibUSB::Configuration::SetAsActive()
{
	m_pConfigImpl_->SetAsActive();
}

bool LibUSB::Configuration::hasExtraDescriptors() const
{
	return m_pConfigImpl_->hasExtraDescriptors();
}

bool LibUSB::Configuration::supportsRemoteWakeup() const
{
	return m_pConfigImpl_->supportsRemoteWakeup();
}

bool LibUSB::Configuration::isSelfPowered() const
{
	return m_pConfigImpl_->isSelfPowered();
}

int LibUSB::Configuration::NumInterfaces() const
{
	return m_pConfigImpl_->NumInterfaces();
}

std::shared_ptr<LibUSB::Interface> LibUSB::Configuration::getInterfaceByIndex( int index ) const
{
	return m_pConfigImpl_->getInterfaceByIndex(index);
}

std::shared_ptr<LibUSB::Interface> LibUSB::Configuration::getInterface( int InterfaceNumber ) const
{
	return m_pConfigImpl_->getInterface(InterfaceNumber);
}

