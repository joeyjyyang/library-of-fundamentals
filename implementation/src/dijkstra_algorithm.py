# Author: Joey Yang
# Student ID: 400026187
# MAC ID: yangj30
# dijstra_algorithm.py

import heapq
import math

class Network:
	network = {}
	link_costs = {}
	visited_routers = {}
	previous_routers = {}
	routing_table = {}
	pq = []

	def __init__(self):
		self.network = { 
		    'u' : {'v': 2, 'w': 5, 'x': 1},
		    'v' : {'u': 2, 'w': 3, 'x': 2},
		    'w' : {'u': 5, 'v': 3, 'x': 3, 'y': 1, 'z': 5},
		    'x' : {'u': 1, 'v': 2, 'w': 3, 'y': 1},
		    'y' : {'w': 1, 'x': 1, 'z': 2},
		    'z' : {'w': 5, 'y': 2}
		}

		self.link_costs = {
			'u' : math.inf,
		    'v' : math.inf,
		    'w' : math.inf,
		    'x' : math.inf,
		    'y' : math.inf,
		    'z' : math.inf
		}

		self.visited_routers = {
			'u' : False,
		    'v' : False,
		    'w' : False,
		    'x' : False,
		    'y' : False,
		    'z' : False
		}

		self.previous_routers = {
			'u' : '',
		    'v' : '',
		    'w' : '',
		    'x' : '',
		    'y' : '',
		    'z' : ''
		}

		self.routing_table = {
			'u' : [],
		    'v' : [],
		    'w' : [],
		    'x' : [],
		    'y' : [],
		    'z' : []
		}

	def dijkstraAlgorithm(self):
		self.source_router = 'u' 
		self.link_costs[self.source_router] = 0 
		heapq.heappush(self.pq, (self.link_costs[self.source_router], self.source_router))

		while self.pq:
			self.current_distance, self.current_router = heapq.heappop(self.pq)
			self.visited_routers[self.current_router] = True
			for self.neighbour_router, self.neighbour_distance in self.network[self.current_router].items():
				if (self.visited_routers[self.neighbour_router]): continue
				else:
					self.new_distance = self.current_distance + self.neighbour_distance
					if (self.new_distance < self.link_costs[self.neighbour_router]):
						self.previous_routers[self.neighbour_router] = self.current_router
						self.link_costs[self.neighbour_router] = self.new_distance 
						heapq.heappush(self.pq, (self.new_distance, self.neighbour_router))
					else:
						pass 

		for self.destination, self.link in self.routing_table.items():
			self.link += self.findShortestRoute(self.destination)

	def findShortestRoute(self, destination):
		self.link = [destination]
		self.temp_destination = destination
		while (self.temp_destination != self.source_router):
			self.link += self.previous_routers[self.temp_destination]
			self.temp_destination = self.previous_routers[self.temp_destination]
		self.link.reverse()
		return self.link

	def printLinkCosts(self):
		for self.router, self.distance in self.link_costs.items():
			print(self.router, self.distance)

	def printPreviousRouters(self):
		for self.router, self.previous_router in self.previous_routers.items():
			print(self.router, self.previous_router)

	def printRoutingTable(self):
		print('Destination', 'Link')
		for self.destination, self.link in self.routing_table.items():
			print(self.destination, self.link)

def main():
	network = Network()
	network.dijkstraAlgorithm()
	network.printRoutingTable()
	#network.printLinkCosts()
	#network.printPreviousRouters()

if __name__ == "__main__":
	main()