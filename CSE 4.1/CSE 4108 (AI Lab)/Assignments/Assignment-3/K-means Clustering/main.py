import csv
import random
import math
import matplotlib.pyplot as plt

def euclidian_distance(x1, y1, x2, y2):
return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

def calc_mean(data_points):
sumx = 0
sumy = 0
n = len(data_points)
for x in data_points:
sumx = sumx + x[0]
sumy = sumy + x[1]

return [sumx / n, sumy / n]

class Kmean:
def __init__(self, k=1, max_itr=1000):
self.k = k
self.centroid = None
self.max_itr = max_itr

def fit(self, x):
rand_ind = random.sample(range(0, len(x)), self.k)
self.centroid = [x[ind] for ind in rand_ind]

for i in range(0, self.max_itr):
clusters = self.assign_cluster(x)
prev_centroid = self.centroid
self.centroid = self.move_centroid(x, clusters)
if self.centroid == prev_centroid:
break
return clusters

def assign_cluster(self, x):
distance = []
clusters = []
for row in x:
for centroid in self.centroid:
x1 = row[0]
y1 = row[1]

x2 = centroid[0]
y2 = centroid[1]
distance.append(euclidian_distance(x1, y1, x2, y2))
min_distance = min(distance)
min_ind = distance.index(min_distance)
clusters.append(min_ind)
distance.clear()
return clusters

def move_centroid(self, x, clusters):
unique_clusters = list(set(clusters))
new_centroid = []
for cluster in unique_clusters:
temp = []
for ind in range(0, len(clusters)):
if cluster == clusters[ind]:
temp.append(x[ind])
new_centroid.append(calc_mean(temp))
return new_centroid

def read_csv():
file = open('custering.csv')
data = csv.reader(file)

header = next(data)
x_train = []
for row in data:

x_train.append([float(row[0]), float(row[1])])

file.close()
return x_train

x_train = read_csv()
kmean = Kmean(k=3)
y_mean = kmean.fit(x_train)
# print(y_mean)

t1 = []
t2 = []
t3 = []

for x in range(0, 2):
for ind in range(0, len(x_train)):
if y_mean[ind] == x:
if x == 0:
t1.append(x_train[ind])
elif x == 1:
t2.append(x_train[ind])
else:
t3.append(x_train[ind])

# plt.scatter([p[0] for p in t1], [p[1] for p in t1], color='green')
# plt.scatter([p[0] for p in t2], [p[1] for p in t2], color='red')
# plt.scatter([p[0] for p in t3], [p[1] for p in t3], color='blue')

# plt.show()
print("Cluster: 0")
print(t1)
print("Cluster: 1")
print(t2)
print("Cluster: 2");
print(t3)