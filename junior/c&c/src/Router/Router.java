package Router;

import IPv4Address.IPv4Address;
import Network.Network;
import Route.Route;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Router {
    private List<Route> routes;

    public Router(Iterable<Route> routes) {
        for ( Route r : routes ) {
            this.routes.add(r);
        }
    }

    public void addRoute(Route route) {
        this.routes.add(route);
    }

//    public Route getRouteForAddress(IPv4Address address) {}

    public Iterable<Route> getRoutes() {
        return this.routes;
    }

//    public void removeRoute(Route route) {}

    public static void main(String[] args) {
        List<Route> routes = new ArrayList<Route>();
        routes.add(new Route(new Network(new IPv4Address("0.0.0.0"), 0),
                    new IPv4Address("192.168.0.1"), "en0", 10));
        routes.add(new Route(new Network(new IPv4Address("192.168.0.0"), 24),
                null, "en0", 10));
        routes.add(new Route(new Network(new IPv4Address("10.0.0.0"), 8),
                    new IPv4Address("10.123.0.1"), "en1", 10));
        routes.add(new Route(new Network(new IPv4Address("10.123.0.0"), 20),
                null, "en1", 10));

        Router router = new Router(routes);


    }
}
