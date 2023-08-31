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
  void setManufacturer(std::string&);
  void setModel(std::string);
  void setSerial_number(std::string);
  void setWattage(int);
  void setNumber_of_channels(int);
  void setBand(std::string);
  void setFrequency(double);
  void setVolume(int);
  void setPower(bool);
  void setLights(std::string);
  void setBass_booster(int);
  void print();
  void print_controls();
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
