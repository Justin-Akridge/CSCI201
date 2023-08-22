#include <iostream>
#include <string>
#include "StereoReceiver.h"

StereoReceiver::StereoReceiver() {
  std::string manufacturer = "";
  std::string model = "";
  std::string serial_number = "";
  int wattage = 0;
  int number_of_channels = 0;
  std::string band = "";
  double frequency = 0.0;
  int volume = 0;
  bool power = 0;
  std::string lights = "";
  int bass_booster = 0;
}

StereoReceiver::StereoReceiver(std::string setManufacturer, std::string setModel, 
                               std::string setSerial_number, int setWattage, 
                               int setNumber_of_channels) {
  std::string manufacturer = setManufacturer;
  std::string model = setModel;
  std::string serial_number = setSerial_number;
  int wattage = setWattage;
  int number_of_channels = setNumber_of_channels;
  std::string band = "AM";
  double frequency = 0.0;
  int volume = 0;
  bool power = 0;
  std::string lights = "off";
  int bass_booster = 0;
}

std::string StereoReceiver:: getManufacturer() const {
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

void StereoReceiver::setManufacturer(std::string& setManufacturer) {
  manufacturer = setManufacturer;
}

void StereoReceiver::setModel(std::string setModel) {
  model = setModel;
}

void StereoReceiver::setSerial_number(std::string setSerial_number) {
  serial_number = setSerial_number;
}

void StereoReceiver::setWattage(int wattage) {
  wattage = setWattage;
}

void StereoReceiver::setNumber_of_channels(int setNumber_of_channels) {
  number_of_channels = setNumber_of_channels;
}

void StereoReceiver::setBand(std::string setBand) {
  band = setBand;
}

void StereoReceiver::setFrequency(double setFrequency) {
  frequency = setFrequency; 
}

void StereoReceiver::setVolume(int setVolume) {
  volume = setVolume;
}

void StereoReceiver::setPower(bool setPower) {
  power = setPower;
}

void StereoReceiver::setLights(std::string setLights) {
  lights = setLights;
}

void setBass_booster(int setBass_booster) {
  bass_booster = setBass_booster;
}
