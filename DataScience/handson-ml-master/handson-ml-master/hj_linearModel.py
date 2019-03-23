from __future__ import division, print_function, unicode_literals

import os
import numpy as np

np.random.seed(42)



import matplotlib as mpl
import matplotlib.pyplot as plt
import pandas as pd
import sklearn

mpl.rc('axes', labelsize=14)
mpl.rc('xtick', labelsize=12)
mpl.rc('ytick', labelsize=12)

PROJECT_ROOT_DIR = '.'
CHAPTER_ID = 'fundamentals'

def save_fig(fig_id, tight_layout=True) :
  path = os.path.join(PROJECT_ROOT_DIR, 'images', CHAPTER_ID, fig_id+'.png')
  print('Saving figure', fig_id)
  if tight_layout:
    plt.tight_layout()
  plt.savefig(path, format='png', dpi=300)

import warnings
warnings.filterwarnings(action='ignore', message='^internal gelsd')

def prepare_country_stats(oecd_bli, gdp_per_capita):
  oecd_bli = oecd_bli[oecd_bli['INEQUALITY']=='TOT']
  oecd_bli = oecd_bli.pivot(index='Country', columns='Indicator', values='Value')
  gdp_per_capita.rename(columns={'2015':'GDP per capita'}, inplace=True)
  gdp_per_capita.set_index('Country', inplace=True)
  full_country_stats = pd.merge(left=oecd_bli, right=gdp_per_capita, left_index=True, right_index=True)
  full_country_stats.sort_values(by='GDP per capita', inplace=True)
  remove_indices = [0,1,6,8,33,34,35]
  keep_indices = list(set(range(36)) - set(remove_indices))
  return full_country_stats[['GDP per capita', 'Life satisfaction']].iloc[keep_indices]


datapath = os.path.join('datasets', 'lifesat', '')

oecd_bli = pd.read_csv('datasets\\lifesat\\oecd_bli_2015.csv', thousands=',')
gdp_per_capita = pd.read_csv('datasets\\lifesat\\gdp_per_capita.csv', thousands=',', delimiter='\t', encoding='latin1', na_values='n/a')

country_stats = prepare_country_stats(oecd_bli, gdp_per_capita)
X = np.c_[country_stats['GDP per capita']]
y = np.c_[country_stats['Life satisfaction']]

country_stats.plot(kind='scatter', x='GDP per capita', y='Life satisfaction')
plt.show()

model = sklearn.linear_model.LinearRegression()

model.fit(X, y)

X_new = [[22587]]
print(model.predict(X_new))

oecd_bli = oecd_bli[oecd_bli['INEQUALITY']=='TOT']
oecd_bli = oecd_bli.pivot(index='Country', columns='Indicator', values='Value')
print(oecd_bli.head(2))