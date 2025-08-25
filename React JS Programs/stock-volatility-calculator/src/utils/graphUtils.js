/* ===================== CHART VISUALIZATION UTILITIES ===================== */
/* Handles creation of interactive price charts using Plotly.js */

// -------- PLOTLY CONFIGURATION --------
const config = {
    displaylogo: false,   // Remove Plotly logo
    modeBarButtonsToRemove: [   // Simplify toolbar buttons
      'zoom2d', 'pan2d', 'select2d', 'lasso2d', 
      'toggleSpikelines', 'resetViews', 'resetScale2d',
      'hoverClosestCartesian', 'hoverCompareCartesian'
    ],
    modeBarButtonsToAdd: [   // Essential tools to keep
      'toImage', 'zoomIn2d', 'zoomOut2d', 'autoScale2d'
    ],
    displayModeBar: true    // Show toolbar
  };
  
  // -------- CHART CREATION FUNCTIONS --------
  
  /**
   * Creates a price deviation chart for a single company
   * @param {string} containerId - DOM element ID for the chart
   * @param {object} data - Company data {name, prices, mean, sd}
   * @param {string[]} days - X-axis labels
   */
  export function createCompanyChart(containerId, data, days) {
    // -------- CHART TRACES --------
    // Price trace (actual prices)
    const priceTrace = {
      x: days,
      y: data.prices,
      type: 'scatter',
      mode: 'lines+markers',
      name: 'Stock Price',
      line: { color: 'blue' },
      marker: { size: 8 }
    };
  
    // Mean price line
    const meanLine = {
      x: days,
      y: Array(days.length).fill(data.mean),
      mode: 'lines',
      name: 'Mean',
      line: { color: 'purple', dash: 'dash' }
    };
  
    // Deviation legend (dummy trace)
    const deviationLegend = {
      x: [null],
      y: [null],
      mode: 'lines',
      type: 'scatter',
      name: 'Deviation',
      line: { color: 'red', width: 2 },
      showlegend: true
    };
  
    // -------- DEVIATION VISUALIZATION --------
    // Error lines between mean and actual prices
    const errorLines = [];
    const annotations = [];
    
    for (let i = 0; i < data.prices.length; i++) {
      // Create deviation lines
      errorLines.push({
        type: 'line',
        x0: days[i],
        x1: days[i],
        y0: data.mean,
        y1: data.prices[i],
        line: { color: 'red', width: 2 }
      });
      
      // Create SD labels
      annotations.push({
        x: days[i],
        y: (data.mean + data.prices[i]) / 2,
        text: formatSD(data.prices[i], data.mean, data.sd),
        showarrow: false,
        font: { color: 'black' }
      });
    }
  
    // -------- CHART LAYOUT --------
    const layout = {  
      title: `<b>${data.name} Stock Price with Volatility</b>`,  
      xaxis: {   
        title: { text: `<b>${days[0].split(' ')[0]}s</b>`, font: { size: 15 } },  
        tickfont: { size: 13 },  
        showgrid: true,
        gridcolor: 'rgb(175,175,175)',
        linecolor: 'rgb(60,60,60)',
        linewidth: 2  
      },  
      yaxis: {   
        title: { text: '<b>Price</b>', font: { size: 15 } },  
        tickfont: { size: 13 },  
        gridcolor: 'rgb(175,175,175)',
        linecolor: 'rgb(60,60,60)',
        linewidth: 2  
      },  
      shapes: errorLines,        // Deviation lines
      annotations: annotations,  // SD labels
      showlegend: true,          // Show chart legend
      margin: { l: 90, r: 60, b: 80, t: 100 }, // Chart margins
      font:  { family: 'Arial, sans-serif', size: 12 }, // Base font
      plot_bgcolor: '#fff',      // Chart area background
      paper_bgcolor: 'lightgrey' // Outer background
    };  
  
    // -------- CHART RENDERING --------
    window.Plotly.newPlot(containerId, [priceTrace, meanLine, deviationLegend], layout, config);
  }
  
  /**
   * Formats deviation in standard deviation units
   * @param {number} price - Actual price
   * @param {number} mean - Mean price
   * @param {number} sd - Standard deviation
   * @returns {string} Formatted SD value
   */
  function formatSD(price, mean, sd) {
    const sdValue = (price - mean) / sd;  // Calculate deviation in SD units
    let sign = sdValue >= 0 ? '+' : '';   // Add '+' sign for positive deviations
    return `${sign}${sdValue.toFixed(2)} SD`; // Format to 2 decimal places
  }
  
  /**
   * Creates charts for both companies
   * @param {object} company1Data - Data for company 1
   * @param {object} company2Data - Data for company 2
   * @param {string} timeframe - Analysis timeframe
   */
  export function createCharts(company1Data, company2Data, timeframe) {
    // Generate X-axis labels based on timeframe
    const label = timeframe === 'daily' ? 'Day' : 
                  timeframe === 'weekly' ? 'Week' : 'Month';
    
    const days = [];
    for (let i = 0; i < company1Data.prices.length; i++) {
      days.push(`${label} ${i + 1}`);
    }
  
    // Clear previous charts
    if (window.Plotly) {
      window.Plotly.purge('company1Chart');
      window.Plotly.purge('company2Chart');
    }
  
    // Create new charts
    createCompanyChart('company1Chart', company1Data, days);
    createCompanyChart('company2Chart', company2Data, days);
  }