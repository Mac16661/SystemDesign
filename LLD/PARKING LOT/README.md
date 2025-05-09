Classes -> 

Class Veichal(Abstract)
    Members:
    #Name
    #Type

    methods:
    +getName(): string
    +getType(): string
=======================
|
|
|inherits
|
|Class bike, car, truck


Class Parking lot(Singleton)
    Members:
    -spot

    method:
    +getAvailabelSpot(vheicleType): void
    +bookAvailableSpot(vheicleType): bool
    +releseParkngSpot(i, vheicleType): bool


mac@OMEN:~/SystemDesign/LLD/PARKING LOT/src$ g++ Driver.cpp Vehicle.cpp -I ../include -o Driver
mac@OMEN:~/SystemDesign/LLD/PARKING LOT/src$ ./Driver 