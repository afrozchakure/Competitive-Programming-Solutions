from sklearn.datasets import fetch_olivetti_faces
import datetime

# Load the dataset
faces = fetch_olivetti_faces()

# Prove the dataset was loaded
# print(faces.data.shape)

class Person:
    def __init__(self, name, photo, date_of_birth):
        self.name = name  # Each argument is copied into the correspoding instance attribute
        self.photo = photo
        self.dob = date_of_birth 

aPerson = Person("Adam", faces.images[0], datetime.datetime(1990, 9, 16))
print(aPerson.name)