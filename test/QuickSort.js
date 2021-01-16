const arr = [5, 4, 3, 2, 1, 1];

const qSort = (array) => {
  if (array.length < 2) {
    return array;
  }

  let pivot = array[0]; //5
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

const res = qSort(arr);

console.log(res);
