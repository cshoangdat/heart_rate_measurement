'use strict'

let bleDevice;
let bleServer;
let floatNumberService;
let tempCharacteristic;
let hrCharacteristic;
let spo2Characteristic;
let tempValue = 29;

window.onload = function(){
  document.querySelector('#connect').addEventListener('click', connect);
  document.querySelector('#disconnect').addEventListener('click', onDisconnectButtonClick);
  document.querySelector('#read').addEventListener('click', readCharacteristicValue);
};

async function connect() {
  try {
    bleDevice = await navigator.bluetooth.requestDevice({
      filters: [{ namePrefix: 'nrf52' }],
      optionalServices: [0x1523]
    });
    bleServer = await bleDevice.gatt.connect();
    floatNumberService = await bleServer.getPrimaryService(0x1523);
    hrCharacteristic = await floatNumberService.getCharacteristic(0x1525);
    spo2Characteristic = await floatNumberService.getCharacteristic(0x1526);

    // Read values from all characteristics
    let [hrDataView, spo2DataView] = await Promise.all([
      readCharacteristicValue(hrCharacteristic),
      readCharacteristicValue(spo2Characteristic)
    ]);

    let hr = hrDataView.getInt32(0, true);
    let spo2 = spo2DataView.getInt32(0, true);

    updateUI(tempValue, hr, spo2);

    // Start notifications for all characteristics
    await hrCharacteristic.startNotifications();
    hrCharacteristic.addEventListener('characteristicvaluechanged', event => {
      let hrValue = event.target.value.getInt32(0, true);
      updateUI(tempValue, hrValue, spo2);
    });

    await spo2Characteristic.startNotifications();
    spo2Characteristic.addEventListener('characteristicvaluechanged', event => {
      let spo2Value = event.target.value.getInt32(0, true);
      updateUI(tempValue, hr, spo2Value);
    });

    setInterval(updateTemperature, 30000); 
  } catch (error) {
    log("Ouch! " + error);
  }
}

async function readCharacteristicValue(characteristic) {
  try {
    let valueDataView = await characteristic.readValue();
    if (valueDataView.byteLength < 4) {
      throw new Error("Insufficient data in DataView");
    }
    return valueDataView;
  } catch (error) {
    log("Error reading characteristic value: " + error);
    throw error;
  }
}

function updateUI(temp, hr, spo2) {
  document.getElementById('temp').textContent = temp;
  document.getElementById('hr').textContent = hr;
  document.getElementById('spo2').textContent = spo2;
}

function updateTemperature() {
  tempValue = Math.round(Math.random() * 2) + 29; // Tạo giá trị nhiệt độ giả lập trong khoảng 29 +/- 1 độ
  updateUI(tempValue, hr, spo2);
}