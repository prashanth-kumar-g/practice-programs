// Strategy interface
interface TravelStrategy {
    void travel(String destination);
}

// Concrete strategy: Car
class CarTravel implements TravelStrategy {
    public void travel(String destination) {
        System.out.println("Driving to " + destination + " by car. Takes more time but gives flexibility.");
    }
}

// Concrete strategy: Train
class TrainTravel implements TravelStrategy {
    public void travel(String destination) {
        System.out.println("Going to " + destination + " by train. Comfortable and affordable.");
    }
}

// Concrete strategy: Plane
class PlaneTravel implements TravelStrategy {
    public void travel(String destination) {
        System.out.println("Flying to " + destination + " by plane. Fastest but most expensive.");
    }
}

// Context class
class TravelPlanner {
    private TravelStrategy strategy;

    // Set the travel strategy (can be changed at runtime)
    public void setStrategy(TravelStrategy strategy) {
        this.strategy = strategy;
    }

    // Execute the selected travel strategy
    public void goTo(String destination) {
        if (strategy == null) {
            System.out.println("Please select a travel strategy first!");
        } else {
            strategy.travel(destination);
        }
    }
}

// Client code
public class StrategyTravelDemo {
    public static void main(String[] args) {
        TravelPlanner planner = new TravelPlanner();

        // Travel using car
        planner.setStrategy(new CarTravel());
        planner.goTo("New York City");

        // Travel using train
        planner.setStrategy(new TrainTravel());
        planner.goTo("New York City");

        // Travel using plane
        planner.setStrategy(new PlaneTravel());
        planner.goTo("New York City");
    }
}
