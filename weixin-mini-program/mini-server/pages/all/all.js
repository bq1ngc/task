Page({
  data: {
    array: []
  },
  tapNameo: function (event) {
    console.log(event.currentTarget.dataset.id)
    var id = event.currentTarget.dataset.id
    wx.navigateTo({
      url: '../post/post?id='+id
    })
  },
  onLoad: function () {
    var that = this
    wx.request({
      url: '..../json.php',
      data: {
      },
      header: {
        'content-type': 'application/json'
      },
      success: function (res) {
        that.setData({
          array: res.data
        })
      }
    })
  },
})