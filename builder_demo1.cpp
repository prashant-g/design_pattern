

#include <iostream>
#include <string>

/* Car parts */
class Wheel
{
    public:
        int size;
};

class Engine
{
    public:
        int horsepower;
};

class Body
{
    public:
        std::string shape;
};

class Car
{
    public:
        Wheel*   wheels[4];
        Engine*  engine;
        Body* body;
    
        void specifications()
        {
            std::cout << "body:" << body->shape << std::endl;
            std::cout << "engine horsepower:" << engine->horsepower << std::endl;
            std::cout << "tire size:" << wheels[0]->size << "'" << std::endl;
        }
};

class Builder
{
    public:
        virtual Wheel* getWheel() = 0;
        virtual Engine* getEngine() = 0;
        virtual Body* getBody() = 0;
};


class SUVBuilder : public Builder
{
    public:
        Wheel* getWheel()
        {
            Wheel* wheel = new Wheel();
            wheel->size = 22;
            return wheel;
        }

        Engine* getEngine()
        {
            Engine* engine = new Engine();
            engine->horsepower = 400;
            return engine;
        }

        Body* getBody()
        {
            Body* body = new Body();
            body->shape = "SUV";
	    return body;
        }
};

class HatchBackBuilder : public Builder
{
    public:
        Wheel* getWheel()
        {
            Wheel* wheel = new Wheel();
            wheel->size = 16;
            return wheel;
        }

        Engine* getEngine()
        {
            Engine* engine = new Engine();
            engine->horsepower = 85;
            return engine;
        }

        Body* getBody()
        {
            Body* body = new Body();
            body->shape = "hatchback";
        }
};
/* Director is responsible for the whole process */
class Director
{
    Builder* builder;
    public:
        void setBuilder(Builder* newBuilder)
        {
            builder = newBuilder;
        }

        Car* buildCar()
        {
            Car* car = new Car();

            car->body = builder->getBody();

            car->engine = builder->getEngine();

            car->wheels[0] = builder->getWheel();
            car->wheels[1] = builder->getWheel();
            car->wheels[2] = builder->getWheel();
            car->wheels[3] = builder->getWheel();

            return car;
        }
};


int main()
{
    Car* car; // Final product

    Director *director= new Director;

    SUVBuilder *suvBuilder= new SUVBuilder();
    HatchBackBuilder *hatchbackBuilder= new HatchBackBuilder();
    
    /* Build a SUV */
    std::cout << "SUV" << std::endl;
    director->setBuilder(suvBuilder); // using suvBuilder instance
    car = director->buildCar();
    car->specifications();

    std::cout << std::endl;

    /* Build a HatchBack */
    std::cout << "hatchback" << std::endl;
    director->setBuilder(hatchbackBuilder); // using NissanBuilder instance
    car = director->buildCar();
    car->specifications();
    Car *car1 = new Car;
    car1->body=hatchbackBuilder->getBody();
    car1->engine=suvBuilder->getEngine();
    car1->wheels[0]=suvBuilder->getWheel();
    car1->specifications();
    delete suvBuilder;
    delete hatchbackBuilder;
    delete director;
    return 0;
}

