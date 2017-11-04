
Page({
  data: {
    array: []
  },
  onLoad: function (options) {
    var that = this
    wx.request({
      url: '../gonggao.php',
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
  }
})