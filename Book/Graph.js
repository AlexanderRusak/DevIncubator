const search = ["Tanya", "Vadim", "Leha"];
let index = 0;
const friendsOfFriends = [
  ["Anya", "Astapova"],
  ["Djora", "Maxim"],
  ["Jenya", "Kirill"],
];
const searched = [];
const isSearched = (arr, current) =>
  arr.find((item) => {
    item === current;
  });

while (search.length != 0) {
  let current = search.shift();
  if (!isSearched(search, current)) {
    searched.push(current);
    if (current[current.length - 1] === "m") {
      console.log("Seller is found ", current);
      return true;
    } else {
      console.log("Seller is not found", index);
      if (friendsOfFriends[index]) {
        search.push(...friendsOfFriends[index]);
      }
      console.log(search);
    }
  }
  index++;
}

console.log(search);
console.log(searched);
