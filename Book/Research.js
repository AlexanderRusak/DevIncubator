let array = [];

const genearateArray = (count) => {
  for (let i = 0; i < count; i++) {
    array.push(Math.floor(Math.random() * Math.floor(count)));
  }
};
const bubbleSort = (inputArr) => {
  let len = inputArr.length;
  for (let i = 0; i < len; i++) {
    for (let j = 0; j < len; j++) {
      if (inputArr[j] > inputArr[j + 1]) {
        let tmp = inputArr[j];
        inputArr[j] = inputArr[j + 1];
        inputArr[j + 1] = tmp;
      }
    }
  }
  return inputArr;
};

const qSort = (array) => {
  if (array.length < 2) {
    return array;
  }

  let pivot = array[0];
  let lessArr = [];
  let largerArr = [];
  for (let i = 1; i < array.length; i++) {
    if (array[i] <= pivot) {
      lessArr.push(array[i]);
    } else {
      largerArr.push(array[i]);
    }
  }
  return [...qSort(lessArr), pivot, ...qSort(largerArr)];
};

const linear =  (arr, target) => {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === target) {
      console.log("linear");
      return arr[i];
    }
  }

  return -1;
};

const binarySearch =  (arr, target) => {
  let start = 0;
  let end = arr.length;
  let pivot = Math.floor((start + end) / 2);
  arr = qSort(arr);

  for (let i = 0; i < arr.length; i++) {
    if (arr[pivot] !== target) {
      if (target < arr[pivot]) end = pivot;
      else start = pivot;
      pivot = Math.floor((start + end) / 2);
    }

    if (arr[pivot] === target) {
      console.log("binary with quick sort");
      return target;
    }
  }
  return -1;
};
const binarySearch2 = async (arr, target) => {
  let start = 0;
  let end = arr.length;
  let pivot = Math.floor((start + end) / 2);
  arr = bubbleSort(arr);

  for (let i = 0; i < arr.length; i++) {
    if (arr[pivot] !== target) {
      if (target < arr[pivot]) end = pivot;
      else start = pivot;
      pivot = Math.floor((start + end) / 2);
    }

    if (arr[pivot] === target) {
      console.log("binary with bubble");
      return target;
    }
  }
  return -1;
};

genearateArray(10000);
//const sortedArray=qSort(array);
//console.log(sortedArray);
const linearPromise = new Promise((res) =>
  setTimeout(() => {
    res();
    linear(array, 1500);
  }, 0)   ///3 -ms linear will be finish last
);

const binaryPromise = new Promise((res) =>
  setTimeout(() => {
    res();
    binarySearch(array, 1500);
  }, 0)
);
const binaryPromise2 = new Promise((res) =>
  setTimeout(() => {
    res();
    binarySearch2(array, 1500);
  }, 0)
);
const promises = [binaryPromise, linearPromise, binaryPromise2];
Promise.race(promises).then(() => {
  console.log("Success");
});
