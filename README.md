# Machine Learning Notebooks
This set of jupyter notebooks supports the machine learning tutorials prepared for the workshop 
[Learning to Discover : Advanced Pattern Recognition](https://indico.cern.ch/event/847626/overview) at Institute Pascal / Paris-Saclay University.

## delphi.ipynb - Tracking by growing a neural gas  (Unsupervised training)
This tutorial demonstrates the use of a Growing Neural Gas (GNG) network to learn the topology of an event as measured by the 
Delphi TPC at CERN. Learning of the tracks happens in unsupervised mode ie. implicitely driven by the density of the measured space points without knowledge of ground truth.

Data files: event2.csv

## ppe.ipynb - Tesselation of a Dalitz plot (Unsupervised training)
This tutorial analyzes the density of a Dalitz plot of the antiproton proton annihilation into the 3 particle
final state $\pi$ $\pi$ $\eta$ (data from Crystal Barrel experiment at CERN). 
A GNG network adapts the probability density function of the plot yielding Voronoi regions
of the same statistics.

Data files: ppe.dat

## pid.ipynb - PID Classification with neural networks (Supervised training)
This example illustrates the classification of particle types using 
[tensorflow](https://www.tensorflow.org/)/[keras](https://keras.io/) neural networks. 
The supervised training is based on a Multilayer Perceptron (MLP) 
with labeled MC generated data of [BaBar](https://www.flickr.com/photos/slaclab/46211844232).

Data files: PidTuple.root

## pidu.ipynb - PID Classification with neural networks (Unsupervised training)
This example illustrates the classification of particle types using 
[tensorflow](https://www.tensorflow.org/)/[keras](https://keras.io/) neural networks. 
The unsupervised training is based on a Growing Neural Gas (GNG) network 
with unlabeled MC generated data of [BaBar](https://www.flickr.com/photos/slaclab/46211844232).

Data files: PidTuple.root
