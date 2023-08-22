#ifndef StereoReceiver_h
#define StereoReceiver_h
#include <string>

class StereoReceiver {
public:
  StereoReceiver();
  StereoReceiver(std::string, std::string, std::string, int, int);
  std::string getManufacturer();
  std::string getModel();
  std::string getSerial_number();
  int getWattage();
  int getNumber_of_channels();
  std::string getBand();
  double getFrequency();
  int getVolume();
  bool getPower();
  std::string getLights();
  int getBass_booster();
  std::string setManufacturer();
  std::string setModel();
  std::string setSerial_number();
  int setWattage();
  int setNumber_of_channels();
  std::string setBand();
  double setFrequency();
  int setVolume();
  bool setPower();
  std::string setLights();
  int setBass_booster();
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
