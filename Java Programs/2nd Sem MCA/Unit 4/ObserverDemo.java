
import java.util.List;
import java.util.ArrayList;

// Observer interface
interface Observer {
    void update(String weatherData);
}

// Concrete Observers
class MobileApp implements Observer {
    public void update(String weatherData) {
        System.out.println("Mobile App: Weather updated - " + weatherData);
    }
}

class Website implements Observer {
    public void update(String weatherData) {
        System.out.println("Website: Weather updated - " + weatherData);
    }
}

// Subject
class WeatherStation {
    private List<Observer> observers = new ArrayList<>();
    private String weather;

    public void addObserver(Observer o) {
        observers.add(o);
    }

    public void removeObserver(Observer o) {
        observers.remove(o);
    }

    public void setWeather(String newWeather) {
        this.weather = newWeather;
        notifyObservers();
    }

    private void notifyObservers() {
        for (Observer o : observers) {
            o.update(weather);
        }
    }
}
public class ObserverDemo {
    public static void main(String[] args) {
        WeatherStation station = new WeatherStation();

        Observer mobile = new MobileApp();
        Observer site = new Website();

        station.addObserver(mobile);
        station.addObserver(site);

        station.setWeather("Sunny 32°C");
    }
}
