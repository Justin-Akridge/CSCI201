#include <iostream>
#include <string>
#include <algorithm>
#include "StereoReceiver.h"

StereoReceiver::StereoReceiver() {
  manufacturer = "";
  model = "";
  serial_number = "";
  wattage = 0;
  number_of_channels = 0;
  band = "";
  frequency = 0.0;
  volume = 0;
  power = false;
  lights = "";
  bass_booster = 0;
}

StereoReceiver::StereoReceiver(std::string setManufacturer, std::string setModel, 
                               std::string setSerial_number, int setWattage, 
                               int setNumber_of_channels) {
  manufacturer = setManufacturer;
  model = setModel;
  serial_number = setSerial_number;
  wattage = setWattage;
  number_of_channels = setNumber_of_channels;
  band = "AM";
  frequency = 0.0;
  volume = 0;
  power = false;
  lights = "off";
  bass_booster = 0;
}

void StereoReceiver::print_controls() {
  std::cout << '\n' << "----------- Controls ----------\n";
  std::cout << "Band: " << band << '\n';
  std::cout << "Frequency: " << frequency << '\n';
  std::cout << "Volume: " << volume << '\n';
  std::cout << "Power: " << power << '\n';
  std::cout << "Lights: " << lights << '\n';
  std::cout << "Bass booster: " << bass_booster << "\n\n";
}

void StereoReceiver::print() {
  std::cout << '\n' << "----------- All Settings -----------\n";
  std::cout << "Manufacturer: " << manufacturer << '\n';
  std::cout << "Model: " << model << '\n';
  std::cout << "Serial Number: " << serial_number << '\n';
  std::cout << "Wattage: " << wattage << '\n';
  std::cout << "Number of channels: " << number_of_channels << '\n';
  std::cout << "Band: " << band << '\n';
  std::cout << "Frequency: " << frequency << '\n';
  std::cout << "Volume: " << volume << '\n';
  std::cout << "Power: " << power << '\n';
  std::cout << "Lights: " << lights << '\n';
  std::cout << "Bass booster: " << bass_booster << "\n\n";
}

std::string StereoReceiver::getManufacturer() const {
  return manufacturer;
}

std::string StereoReceiver::getModel() const {
  return model;
}

std::string StereoReceiver::getSerial_number() const {
  return serial_number;
}

int StereoReceiver::getWattage() const {
  return wattage;
}

int StereoReceiver::getNumber_of_channels() const {
  return number_of_channels;
}

std::string StereoReceiver::getBand() const {
  return band;
}

double StereoReceiver::getFrequency() const {
  return frequency;
}

int StereoReceiver::getVolume() const {
  return volume;
}

bool StereoReceiver::getPower() const {
  return power;
}

std::string StereoReceiver::getLights() const {
  return lights;
}

int StereoReceiver::getBass_booster() const {
  return bass_booster;
}

bool is_valid_string(std::string s) {
  for (int i = 0; i < s.size(); i++) {
    if (!isspace(s[i]) || !isalpha(s[i] || s[i] == '-')) {
      return false;
    }
  }
  return true;
}

void StereoReceiver::setManufacturer(std::string& setManufacturer) {
  try {
    if (is_valid_string(setManufacturer))
      manufacturer = setManufacturer;
    else
      throw setManufacturer;
  } catch (std::string setManufacturer) {
    std::cout << setManufacturer << " is an invalid manufacturer\n";
  }
}

void StereoReceiver::setModel(std::string setModel) {
  try {
    if (is_valid_string(setModel))
      model = setModel;
    else
      throw setModel;
  } catch (std::string setModel) {
    std::cout << setModel << " is an invalid model\n";
  }
}

void StereoReceiver::setSerial_number(std::string setSerial_number) {
  try {
    if (is_valid_string(setSerial_number)) 
      serial_number = setSerial_number;
    else
      throw setSerial_number;
  } catch (std::string setSerial_number) {
    std::cout << setSerial_number << "  is invalid serial number\n";
  }
}

void StereoReceiver::setWattage(int setWattage) {
  try {
    if (setWattage > 0 && setWattage < 100) 
      wattage = setWattage;
    else
      throw setWattage;
  } catch (int setWattage) {
    if (setWattage < 0) {
      std::cout << "Watts must be above 0\n"; 
    }
    else {
      std::cout << "Watts must be below 100\n";
    }
}

void StereoReceiver::setNumber_of_channels(int setNumber_of_channels) {
  try {
    if (setNumber_of_channels > 0 && setNumber_of_channels < 110)
      number_of_channels = setNumber_of_channels;
    else
      throw setNumber_of_channels;
  } catch(setNumber_of_channels) {
    if (setNumber_of_channels < 0) {
      std::cout << "Number of channels must be greater then 0\n";
    } else {
      std::cout << "Number of channels must be less then 110 channels\n";
    }
  }
}

void StereoReceiver::setBand(std::string setBand) {
  try {
    std::to_lower(setBand);
    if (is_valid_string(setBand) && setBand == "am" || setBand == "fm")
      band = setBand;
    else 
      throw setBand;
  } catch (std::string setBand) {
    std::cout << "You must enter am or fm\n";
  }
}

void StereoReceiver::setFrequency(double setFrequency) {
  try {
    if (setFrequency >= 0.0 && setFrequency <= 50.0)
      frequency = setFrequency; 
    else 
      throw setFrequency;
  } catch (double setFrequency) {
    if (setFrequency < 0.0) {
      std::cout << "Frenquency must be greater than or equal to 0\n";
    } else {
      std::cout << "Frenquency must be less than or equal to 50\n";
    }
  }
}

void StereoReceiver::setVolume(int setVolume) {
  try {
    if (setVolume >= 0 && setVolume <= 50)
      volume = setVolume;
    else 
      throw setVolume;
  } catch (int setVolume) {
    if (setVolume < 0) {
      std::cout << "Volume must be greater then or equal to 0\n";
    } else {
      std::cout << "Volume only goes up to 50\n";
    }
  }
}

void StereoReceiver::setPower(bool setPower) {
  try {
    if (setPower || !setPower)
      power = setPower;
    else 
      throw setPower;
  } catch (bool setPower) {
    std::cout << "You must enter true or false\n";
  }
}

void StereoReceiver::setLights(std::string setLights) {
  try {
    std::to_lower(setLights);
    if (is_valid_string(setLights) && setLights == "on" || setLights == "false")
      lights = setLights;
    else
  } catch (std::string setLights) {
    std::cout << "You must enter on or off\n";
  }
}

void StereoReceiver::setBass_booster(int setBass_booster) {
  try {
    if (bass_booster >= 0 && bass_booster <= 10)
      bass_booster = setBass_booster;
    else
      throw setBass_booster;
  } catch (int setBass_booster) {
    if (setBass_booster < 0) {
      std::cout << "You must enter value greater then 0\n";
    } else {
      std::cout << "You must enter value less then 11\n";
    }
}
