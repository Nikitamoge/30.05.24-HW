#include <iostream>
#include <string>
using namespace std;

class RotatingDrum
{
public:
    void Rotate()
    {
        cout << "The rotating drum is spinning" << endl;
    }
};

class MachineEngine
{
public:
    void Initiate()
    {
        cout << "The machine engine is initiating" << endl;
    }
    void Terminate()
    {
        cout << "The machine engine is terminating" << endl;
    }
};

class WaterSupplySystem
{
public:
    void SupplyWater()
    {
        cout << "The water supply system is filling water" << endl;
    }
};

class WaterDrainageSystem
{
public:
    void DrainWater()
    {
        cout << "The water drainage system is draining water" << endl;
    }
};

class WashingMachineFacade
{
    RotatingDrum rotatingDrum;
    MachineEngine machineEngine;
    WaterSupplySystem waterSupplySystem;
    WaterDrainageSystem waterDrainageSystem;
public:
    WashingMachineFacade(RotatingDrum rotatingDrum, MachineEngine machineEngine, WaterSupplySystem waterSupplySystem, WaterDrainageSystem waterDrainageSystem)
    {
        this->rotatingDrum = rotatingDrum;
        this->machineEngine = machineEngine;
        this->waterSupplySystem = waterSupplySystem;
        this->waterDrainageSystem = waterDrainageSystem;
    }
    void StartWashing()
    {
        machineEngine.Initiate();
        rotatingDrum.Rotate();
        waterSupplySystem.SupplyWater();
    }
    void StopWashing()
    {
        waterDrainageSystem.DrainWater();
        machineEngine.Terminate();
    }
};

class User
{
public:
    void UseWashingMachine(WashingMachineFacade washingMachineFacade)
    {
        washingMachineFacade.StartWashing();
        washingMachineFacade.StopWashing();
    }
};

int main()
{
    RotatingDrum rotatingDrum;
    MachineEngine machineEngine;
    WaterSupplySystem waterSupplySystem;
    WaterDrainageSystem waterDrainageSystem;

    WashingMachineFacade washingMachineFacade(rotatingDrum, machineEngine, waterSupplySystem, waterDrainageSystem);

    User user;
    user.UseWashingMachine(washingMachineFacade);
}