package Router;

import IPv4Address.IPv4Address;
import IPv4Address.IPAddressException;
import Network.Network;
import Route.Route;

import java.util.TreeSet;
import java.util.Collection;
import java.util.ArrayList;
import java.util.List;

public class Router {
    private TreeSet<Route> routes;

    public Router(Iterable<Route> routes) {
        this.routes = new TreeSet<Route>((Collection<Route>)routes);
    }

    public void addRoute(Route route) {
        this.routes.add(route);
    }

    public Route getRouteForAddress(IPv4Address address) throws IPAddressException {
        for ( Route r : this.routes ) {
            if (r.getNetwork().contains(address)) {
                return r;
            }
        }
        return null;
    }

    public Iterable<Route> getRoutes() {
        return this.routes;
    }

    public void removeRoute(Route route) {
        this.routes.remove(route);
    }

    public static void main(String[] args) throws IPAddressException {
        List<Route> routes = new ArrayList<Route>() {{
            add(new Route(new Network(new IPv4Address("0.0.0.0"), 0), new IPv4Address("192.168.0.1"), "en0", 10));
            add(new Route(new Network(new IPv4Address("192.168.0.0"), 24), null, "en0", 10));
            add(new Route(new Network(new IPv4Address("10.0.0.0"), 8), new IPv4Address("10.123.0.1"), "en1", 10));
            add(new Route(new Network(new IPv4Address("10.123.0.0"), 20), null, "en1", 10));
            add(new Route(new Network(new IPv4Address("255.255.255.251"), 30), null, "en1", 10));
            add(new Route(new Network(new IPv4Address("255.255.255.251"), 30), null, "en1", 11));
        }};

        Router router = new Router(routes);

        Route route = router.getRouteForAddress(new IPv4Address("192.168.0.176"));
        System.out.println(route.getMetric());                  // 10
        System.out.println(route.getInterfaceName());           // en0

        Network net = route.getNetwork();
        System.out.println(net.toString());                     // 192.168.0.0/24
        System.out.println(net.getAddress().toString());        // 192.168.0.0

        route = router.getRouteForAddress(new IPv4Address("10.0.1.1"));
        System.out.println(route.getMetric());                  // 10
        System.out.println(route.getInterfaceName());           // en1
        net = route.getNetwork();
        System.out.println(net.toString());                     // 10.0.0.0/8


        for ( Route r : router.getRoutes() ) {
            System.out.println(r);
        }
    }
}