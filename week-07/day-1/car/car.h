#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

typedef enum{
    VOLVO,
    TOYOTA,
    LAND_ROVER,
    TESLA } car_type;

typedef struct{
    car_type type;
	double km;
	double gas;
}car;


#endif // CAR_H_INCLUDED
