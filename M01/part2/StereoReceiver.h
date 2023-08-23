#ifndef StereoReceiver_h
#define StereoReceiver_h
#include <string>

class StereoReceiver {
public:
  StereoReceiver();
  StereoReceiver(std::string, std::string, std::string, int, int);
  std::string getManufacturer() const;
  std::string getModel() const;
  std::string getSerial_number() const;
  int getWattage() const;
  int getNumber_of_channels() const;
  std::string getBand() const;
  double getFrequency() const;
  int getVolume() const;
  bool getPower() const;
  std::string getLights() const;
  int getBass_booster() const;
  int setManufacturer(std::string&);
  int setModel(std::string);
  int setSerial_number(std::string);
  int setWattage(int);
  int setNumber_of_channels(int);
  int setBand(std::string);
  int setFrequency(double);
  int setVolume(int);
  int setPower(bool);
  int setLights(std::string);
  int setBass_booster(int);
private:
  std::string manufacturer;
  std::string model;
  std::string serial_number;
  int wattage;
  int number_of_channels;
  std::string band;
  double frequency;
  int volume;
  bool power;
  std::string lights;
  int bass_booster;
};

#endif
