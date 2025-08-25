/* ===================== STATISTICAL CALCULATION UTILITIES ===================== */
/* Core functions for volatility calculations (Mean, SD, CV) */

// -------- STATISTICAL FUNCTIONS --------

/**
 * Calculates the sum of values in an array
 * @param {number[]} arr - Array of numerical values
 * @returns {number} Sum of all values
 */
export const calcSum = (arr) => {
    return arr.reduce((sum, val) => sum + val, 0);
  };
  
  /**
   * Calculates the mean (average) of values
   * @param {number} sum - Sum of all values
   * @param {number} period - Number of values
   * @returns {number} Mean value
   */
  export const calcMean = (sum, period) => {
    return sum / period;
  };
  
  /**
   * Calculates the sum of squared deviations from the mean
   * @param {number[]} arr - Array of numerical values
   * @param {number} mean - Mean value
   * @returns {number} Sum of squared deviations
   */
  export const calcSumDev = (arr, mean) => {
    return arr.reduce((sum, val) => sum + Math.pow(val - mean, 2), 0);
  };
  
  /**
   * Calculates the standard deviation
   * @param {number} sumdev - Sum of squared deviations
   * @param {number} period - Number of values
   * @returns {number} Standard deviation
   */
  export const calcSD = (sumdev, period) => {
    const variance = sumdev / period;
    return Math.sqrt(variance);
  };
  
  /**
   * Calculates all statistics for a company
   * @param {number[]} prices - Array of stock prices
   * @returns {object} Statistical metrics {sum, mean, sumdev, sd, cv}
   */
  export const calculateCompanyStats = (prices) => {
    const period = prices.length;
    const sum = calcSum(prices);
    const mean = calcMean(sum, period);
    const sumdev = calcSumDev(prices, mean);
    const sd = calcSD(sumdev, period);
    const cv = (sd / mean) * 100;  // Coefficient of Variation
    
    return { sum, mean, sumdev, sd, cv, prices };
  };