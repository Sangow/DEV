package Router;

import IPv4Address.IPv4Address;
import Network.Network;
import Route.Route;
import com.sun.security.jgss.GSSUtil;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.SortedSet;

public class Router {
    public ArrayList<Route> routes;

    public Router(Iterable<Route> routes) {
        this.routes = (ArrayList)routes;
    }

    public void addRoute(Route route) {
        if ( this.routes.contains(route) ) {
            return;
        }
        this.routes.add(route);
    }

    public Route getRouteForAddress(IPv4Address address) {
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

    public static void main(String[] args) {
        List<Route> routes = new ArrayList<Route>();
        routes.add(new Route(new Network(new IPv4Address("0.0.0.0"), 0),
                new IPv4Address("192.168.0.1"), "en0", 3));
        routes.add(new Route(new Network(new IPv4Address("192.168.0.0"), 24),
                null, "en0", 2));
        routes.add(new Route(new Network(new IPv4Address("10.0.0.0"), 8),
                    new IPv4Address("10.123.0.1"), "en1", 1));
        routes.add(new Route(new Network(new IPv4Address("10.123.0.0"), 24),
                null, "en1", 0));

        Router router = new Router(routes);

        Route route = router.getRouteForAddress(new IPv4Address("192.168.0.176"));

        System.out.println(route.getMetric());                  // 10
        System.out.println(route.getInterfaceName());           // en0
        System.out.println(route.toString());

        Network net = route.getNetwork();
        System.out.println(net.toString());                     // 192.168.0.0/24
        System.out.println(net.getAddress().toString());        // 192.168.0.0

        route = router.getRouteForAddress(new IPv4Address("10.0.1.1"));
        System.out.println(route.getMetric());                  // 10
        System.out.println(route.getInterfaceName());           // en1
        net = route.getNetwork();
        System.out.println(net.toString());                     // 10.0.0.0/8

        Network neet = new Network(new IPv4Address("0.0.0.0"), 0);
        System.out.println(neet.contains(new IPv4Address("192.168.0.0")));

        System.out.println(routes.toString());
    }
}
