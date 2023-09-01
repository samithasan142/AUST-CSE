import math
from collections import Counter
import csv


def read_data():
    file = open('Social_Network_Ads.csv')
    data = csv.reader(file)

    header = next(data)

    x_train = []
    y_train = []

    for row in data:
        # the index no 2 is Age and 3 is Salary which are two features I used to predict
        x_train.append([int(row[2]), float(row[3])])
        # index 4 is class
        y_train.append(int(row[4]))

    file.close()
    return x_train, y_train


def euclidian_distance(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


def argsort(x):
    return sorted(range(len(x)), key=x.__getitem__)


class KNN:

    def __init__(self, k=2):
        self.Y_train = None
        self.X_train = None
        self.k = k

    def fit(self, x, y):
        self.X_train = x
        self.Y_train = y

    def predict(self, x):
        # compute distance
        distances = []
        for feature in self.X_train:
            x1 = feature[0]
            y1 = feature[1]
            x2 = x[0]
            y2 = x[1]
            distances.append(euclidian_distance(x1, y1, x2, y2))

        # k nearest labels
        k_indices = argsort(distances)[:self.k]

        # find labels
        k_nearest_labels = [self.Y_train[ind] for ind in k_indices]
        most_common = Counter(k_nearest_labels).most_common(1)
        return most_common[0][0]


x_train, y_train = read_data()
clf = KNN(k=3)
clf.fit(x_train, y_train)
test = [48, 29000]
print(clf.predict(test))
