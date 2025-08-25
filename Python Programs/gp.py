import matplotlib.pyplot as plt
import numpy as np

# TCS Data
tcs_prices = [1000, 1050, 1100, 1050, 1000]
tcs_mean = np.mean(tcs_prices)
tcs_sd = 37.42

# RIL Data
ril_prices = [1010, 1100, 1150, 1100, 1200]
ril_mean = np.mean(ril_prices)
ril_sd = 63.06

days = ["Day 1", "Day 2", "Day 3", "Day 4", "Day 5"]

# Function to calculate (mean - xi) / SD and format with +/-
def format_sd_value(price, mean, sd):
    sd_value = (mean - price) / sd
    return f"{sd_value:+.2f} SD"  # Add + sign for positive values

# TCS Graph
plt.figure(figsize=(8, 4))
plt.plot(days, tcs_prices, marker='o', label="Stock Price", color='blue')
plt.axhline(y=tcs_mean, color='purple', linestyle='--', label="TCS Mean")

# One-sided error bars (only downward towards the mean) with labels
for i, price in enumerate(tcs_prices):
    plt.vlines(days[i], tcs_mean, price, colors='red', linestyles='solid', label="Deviation" if i == 0 else "")
    sd_label = format_sd_value(price, tcs_mean, tcs_sd)
    plt.text(days[i], (tcs_mean + price) / 2, sd_label, color='black', ha='center')

plt.title("TCS Stock Price with Volatility")
plt.legend()
plt.grid(True)
plt.show()

# RIL Graph
plt.figure(figsize=(8, 4))
plt.plot(days, ril_prices, marker='o', label="Stock Price", color='green')
plt.axhline(y=ril_mean, color='purple', linestyle='--', label="RIL Mean")

# One-sided error bars (only downward towards the mean) with labels
for i, price in enumerate(ril_prices):
    plt.vlines(days[i], ril_mean, price, colors='red', linestyles='solid', label="Deviation" if i == 0 else "")
    sd_label = format_sd_value(price, ril_mean, ril_sd)
    plt.text(days[i], (ril_mean + price) / 2, sd_label, color='black', ha='center')

plt.title("RIL Stock Price with Volatility")
plt.legend()
plt.grid(True)
plt.show()